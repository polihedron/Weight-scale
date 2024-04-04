/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "../../Drivers/MB85RS64V/fram.h"
#include "../../Drivers/ili9341/core.h"
#include "../../Drivers/XPT2046/XPT2046.h"
#include "simple_filters.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */




#define FRAM_CS_DISABLE HAL_GPIO_WritePin(FRAM_CS_GPIO_Port, FRAM_CS_Pin, 1)


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

//typedef struct
//{
//	int32_t weight_avg;;
//	uint32_t raw_avg;
//} weight_data_avg_t;

uint8_t TxData[8] = { 0b0000000, 0x00000001, 0b01010101, 0b01010101, 0b01010101, 0b01010101, 0b01010101, 0b01010101 };  // clock, 25 ticks
uint8_t RxData[8];
uint64_t raw_reading;
uint8_t sensor_read_flag = 0;

double raw;
int32_t weight_avg;
uint32_t raw_avg;
uint32_t raw_avg_offset;
uint32_t SoftTimer;

//double CalibrationX0 = 0;
//double CalibrationY0 = 0;
//double CalibrationX1 = 0;
//double CalibrationY1 = 0;
double CalibrationX0 = CALIBRATION_X0;
double CalibrationY0 = CALIBRATION_Y0;
double CalibrationX1 = CALIBRATION_X1;
double CalibrationY1 = CALIBRATION_Y1;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

int32_t get_weight(uint32_t  result);
void get_raw_weight(double *raw_reading );
void doMeasure (void);
void doMemories(void);


void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if (hspi->Instance == SPI2)
	{
		sensor_read_flag = 1;
	}
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern void touchgfxSignalVSync(void);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2) {
		touchgfxSignalVSync();  //i'am dk why but i turned off the vSync in Cube but i still have to get infi :/
	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  FRAM_CS_DISABLE;

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_SPI2_Init();
  MX_SPI3_Init();
  MX_TIM2_Init();
  MX_CRC_Init();
  MX_SPI5_Init();
  MX_TouchGFX_Init();

  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */
  setSPI_FRAM_Handle(&hspi1);
  FRAM_init();
  doMemories();
  HAL_TIM_Base_Start_IT(&htim2);
  ILI9341_Init();
  XPT2046_Init(&hspi3, EXTI9_5_IRQn);
  touchgfxSignalVSync();

//  DoCalibration();

  HAL_SPI_TransmitReceive_DMA(&hspi2, (uint8_t*) (&TxData),(uint8_t*) (&RxData), sizeof(TxData));
  SoftTimer = HAL_GetTick();
  filter_moving_average_init();
  raw_avg_offset = CalibrationX0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  XPT2046_Task();

	  doMeasure();

    /* USER CODE END WHILE */

  MX_TouchGFX_Process();
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* EXTI9_5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
  /* DMA2_Stream4_IRQn interrupt configuration */
  NVIC_SetPriority(DMA2_Stream4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
  NVIC_EnableIRQ(DMA2_Stream4_IRQn);
}

/* USER CODE BEGIN 4 */


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == TOUCH_IRQ_Pin)
	{
		XPT2046_IRQ();
	}

}
void doMemories(void)	{

	typedef union
	{
	    uint32_t split[2];
	    double d_value;
	} split_double;
	split_double cx0 = {0};
	split_double cy0 = {0};
	split_double cx1 = {0};
	split_double cy1 = {0};



	uint8_t memory_init = FRAM_read8(0x0000);
	if (memory_init != 0xCC)	{
		FRAM_write8(0x0000, 0xCC);
		cx0.d_value = CalibrationX0;
		cy0.d_value = CalibrationY0;
		cx1.d_value = CalibrationX1;
		cy1.d_value = CalibrationY1;
		FRAM_write32(0x0001, cx0.split[0]);
		FRAM_write32(0x0005, cx0.split[1]);
		FRAM_write32(0x0009, cy0.split[0]);
		FRAM_write32(0x000D, cy0.split[1]);
		FRAM_write32(0x0011, cx1.split[0]);
		FRAM_write32(0x0015, cx1.split[1]);
		FRAM_write32(0x0019, cy1.split[0]);
		FRAM_write32(0x001D, cy1.split[1]);
	}

	else	{

		cx0.split[0] = FRAM_read32(0x0001);
		cx0.split[1] = FRAM_read32(0x0005);
		cy0.split[0] = FRAM_read32(0x0009);
		cy0.split[1] = FRAM_read32(0x000D);
		cx1.split[0] = FRAM_read32(0x0011);
		cx1.split[1] = FRAM_read32(0x0015);
		cy1.split[0] = FRAM_read32(0x0019);
		cy1.split[1] = FRAM_read32(0x001D);

		CalibrationX0 = cx0.d_value;
		CalibrationY0 = cy0.d_value;
		CalibrationX1 = cx1.d_value;
		CalibrationY1 = cy1.d_value;
	}


}

void saveMemories(void)	{

	typedef union
	{
	    uint32_t split[2];
	    double d_value;
	} split_double;
	split_double cx0 = {0};
	split_double cy0 = {0};
	split_double cx1 = {0};
	split_double cy1 = {0};
	cx0.d_value = CalibrationX0;
	cy0.d_value = CalibrationY0;
	cx1.d_value = CalibrationX1;
	cy1.d_value = CalibrationY1;


	uint8_t memory_init = FRAM_read8(0x0000);
	if (memory_init == 0xCC)	{
		//FRAM_write8(0x0000, 0xCC);
		FRAM_write32(0x0001, cx0.split[0]);
		FRAM_write32(0x0005, cx0.split[1]);
		FRAM_write32(0x0009, cy0.split[0]);
		FRAM_write32(0x000D, cy0.split[1]);
		FRAM_write32(0x0011, cx1.split[0]);
		FRAM_write32(0x0015, cx1.split[1]);
		FRAM_write32(0x0019, cy1.split[0]);
		FRAM_write32(0x001D, cy1.split[1]);
	}

}


void doMeasure (void) {

 if (sensor_read_flag == 1)	{

	  get_raw_weight( &raw );
  }

 uint32_t raw_filter = filter_moving_average_uint(raw);

	if ((sensor_read_flag == 1) && (HAL_GPIO_ReadPin(SPI2_MISO_GPIO_Port, SPI2_MISO_Pin) == GPIO_PIN_RESET))
	{
		sensor_read_flag = 0;
		HAL_SPI_TransmitReceive_DMA(&hspi2, (uint8_t*) (&TxData), (uint8_t*) (&RxData), sizeof(TxData));
	}

	  if ((HAL_GetTick() - SoftTimer) > 500) {

		  raw_avg = raw_filter;
		  weight_avg  = get_weight(raw_avg)- get_weight(raw_avg_offset);


		if	(weight_avg > 15000 )
		{
			weight_avg = 15000;
		}

		SoftTimer = HAL_GetTick();
	  }

}



void get_raw_weight(double *raw_reading )	{

	*raw_reading = (((uint64_t) (RxData[7] & 0b00000010)) >> 1)
			| (((uint64_t) (RxData[7] & 0b00001000)) >> 2)
			| (((uint64_t) (RxData[7] & 0b00100000)) >> 3)
			| (((uint64_t) (RxData[7] & 0b10000000)) >> 4)
			| (((uint64_t) (RxData[6] & 0b00000010)) << 3)
			| (((uint64_t) (RxData[6] & 0b00001000)) << 2)
			| (((uint64_t) (RxData[6] & 0b00100000)) << 1)
			| (((uint64_t) (RxData[6] & 0b10000000)) << 0) |

			(((uint64_t) (RxData[5] & 0b00000010)) << 7)
			| (((uint64_t) (RxData[5] & 0b00001000)) << 6)
			| (((uint64_t) (RxData[5] & 0b00100000)) << 5)
			| (((uint64_t) (RxData[5] & 0b10000000)) << 4)
			| (((uint64_t) (RxData[4] & 0b00000010)) << 11)
			| (((uint64_t) (RxData[4] & 0b00001000)) << 10)
			| (((uint64_t) (RxData[4] & 0b00100000)) << 9)
			| (((uint64_t) (RxData[4] & 0b10000000)) << 8) |

			(((uint64_t) (RxData[3] & 0b00000010)) << 15)
			| (((uint64_t) (RxData[3] & 0b00001000)) << 14)
			| (((uint64_t) (RxData[3] & 0b00100000)) << 13)
			| (((uint64_t) (RxData[3] & 0b10000000)) << 12)
			| (((uint64_t) (RxData[2] & 0b00000010)) << 19)
			| (((uint64_t) (RxData[2] & 0b00001000)) << 18)
			| (((uint64_t) (RxData[2] & 0b00100000)) << 17)
			| (((uint64_t) (RxData[2] & 0b10000000)) << 16) |

			(((uint64_t) (RxData[1] & 0b00000010)) << 23)
			| (((uint64_t) (RxData[1] & 0b00001000)) << 22)
			| (((uint64_t) (RxData[1] & 0b00100000)) << 21)
			| (((uint64_t) (RxData[1] & 0b10000000)) << 20);

}



int32_t get_weight(uint32_t  raw_reading )	{

	int32_t result = (CalibrationY1 - CalibrationY0) / (CalibrationX1 - CalibrationX0) * ((double )raw_reading - CalibrationX1) + CalibrationY1;
	return result;
}




/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
