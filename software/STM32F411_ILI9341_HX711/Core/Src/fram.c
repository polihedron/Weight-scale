/*
 * fram.c
 *
 *  Created on: Oct 31, 2022
 *      Author: edrag
 */
#include "fram.h"
#include "spi.h"
#include "gpio.h"

#define FRAM_CS_ENABLE HAL_GPIO_WritePin(FRAM_CS_GPIO_Port, FRAM_CS_Pin, 0);
#define FRAM_CS_DISABLE HAL_GPIO_WritePin(FRAM_CS_GPIO_Port, FRAM_CS_Pin, 1);
//#define FRAM_WP_ENABLE HAL_GPIO_WritePin(FRAM_WP_GPIO_Port, FRAM_WP_Pin, 0);
//#define FRAM_WP_DISABLE HAL_GPIO_WritePin(FRAM_WP_GPIO_Port, FRAM_WP_Pin, 1);



void FRAM_init(void)
{
	uint8_t spiCMD;

	spiCMD = FRAM_RDID;
    FRAM_CS_ENABLE;
   // FRAM_WP_DISABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;

    spiCMD = FRAM_WRDI;
    FRAM_CS_ENABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;

    spiCMD = FRAM_WREN;
    FRAM_CS_ENABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;

    spiCMD = FRAM_WRSR;
    FRAM_CS_ENABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;

    spiCMD = FRAM_SR_WEL;
    FRAM_CS_ENABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;

    spiCMD = FRAM_RDSR;
    FRAM_CS_ENABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;

    spiCMD = FRAM_NULL;
    FRAM_CS_ENABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;
   // FRAM_WP_ENABLE;
}


uint8_t FRAM_read8(uint16_t address)
{
	uint8_t spiCMD;
	uint8_t spiAddrByte;
	uint8_t byte;

	spiCMD = FRAM_READ;
    //enable Chip Select
    FRAM_CS_ENABLE;
   // FRAM_WP_ENABLE;
    //send read command
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    //send upper 8 bits of address
    spiAddrByte = ((address&0x3f00)>>8);
    HAL_SPI_Transmit(&hspi1, &spiAddrByte, sizeof(spiAddrByte), HAL_MAX_DELAY);
    //send lower 8 bits of address
    spiAddrByte = (address&0x00ff);
    HAL_SPI_Transmit(&hspi1, &spiAddrByte, sizeof(spiAddrByte), HAL_MAX_DELAY);
    //receive data byte
    HAL_SPI_Receive(&hspi1, &byte, sizeof(byte), HAL_MAX_DELAY);
    //disable Chip Select
    FRAM_CS_DISABLE;

    return(byte);
}



void FRAM_write8(uint16_t address, uint8_t byte)
{
	uint8_t spiCMD;
	uint8_t spiAddrByte;

	spiCMD = FRAM_WREN;
    FRAM_CS_ENABLE;
   // FRAM_WP_DISABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;

    spiCMD = FRAM_WRITE;
    //enable Chip Select
    FRAM_CS_ENABLE;
    //send WRITE command
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    //send upper 8 bits of address
    spiAddrByte = ((address&0x3f00)>>8);
    HAL_SPI_Transmit(&hspi1, &spiAddrByte, sizeof(spiAddrByte), HAL_MAX_DELAY);
    //send lower 8 bits of address
    spiAddrByte = (address&0x00ff);
    HAL_SPI_Transmit(&hspi1, &spiAddrByte, sizeof(spiAddrByte), HAL_MAX_DELAY);
    //sent data byte
    HAL_SPI_Transmit(&hspi1, &byte, sizeof(byte), HAL_MAX_DELAY);
    //disable Chip Select
    FRAM_CS_DISABLE;
   // FRAM_WP_ENABLE;
}


uint32_t FRAM_read32(uint16_t address)
{
	uint8_t spiCMD;
	uint8_t spiAddrByte;
	uint32_t data;

	spiCMD = FRAM_READ;
    //enable Chip Select
    FRAM_CS_ENABLE;
    //send WRITE command
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    //send upper 8 bits of address
    spiAddrByte = ((address&0x3f00)>>8);
    HAL_SPI_Transmit(&hspi1, &spiAddrByte, sizeof(spiAddrByte), HAL_MAX_DELAY);
    //send lower 8 bits of address
    spiAddrByte = (address&0x00ff);
    HAL_SPI_Transmit(&hspi1, &spiAddrByte, sizeof(spiAddrByte), HAL_MAX_DELAY);
    //receive data byte
    	//for ( uint16_t i = 0 ; i < nBytes ; i++ )
    	//{
    		HAL_SPI_Receive(&hspi1, &data,  sizeof(data), HAL_MAX_DELAY);
    		//data[i] = byte;
    	//}

    //disable Chip Select
    FRAM_CS_DISABLE;

    return data;
}


void FRAM_write32(uint16_t address, uint32_t data)
{
	uint8_t spiCMD;
	uint8_t spiAddrByte;

	spiCMD = FRAM_WREN;
    FRAM_CS_ENABLE;
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    FRAM_CS_DISABLE;

    spiCMD = FRAM_WRITE;
    //enable Chip Select
    FRAM_CS_ENABLE;
    //send WRITE command
    HAL_SPI_Transmit(&hspi1, &spiCMD, sizeof(spiCMD), HAL_MAX_DELAY);
    //send upper 8 bits of address
    spiAddrByte = ((address&0x3f00)>>8);
    HAL_SPI_Transmit(&hspi1, &spiAddrByte, sizeof(spiAddrByte), HAL_MAX_DELAY);
    //send lower 8 bits of address
    spiAddrByte = (address&0x00ff);
    HAL_SPI_Transmit(&hspi1, &spiAddrByte, sizeof(spiAddrByte), HAL_MAX_DELAY);
    //sent data byte

	//for ( uint16_t i = 0 ; i < nBytes ; i++ )
	//{
		HAL_SPI_Transmit(&hspi1, &data, sizeof(data), HAL_MAX_DELAY);
		//data[i] = byte;
	//}


    //disable Chip Select
    FRAM_CS_DISABLE;
}
