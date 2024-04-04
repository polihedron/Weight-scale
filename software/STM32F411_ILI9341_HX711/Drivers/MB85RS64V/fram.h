/*
 * fram.h
 *
 *  Created on: Oct 31, 2022
 *      Author: edrag
 */

#ifndef INC_FRAM_H_
#define INC_FRAM_H_

#include "stm32f4xx_hal.h"

#define FRAM_WREN    0x06
#define FRAM_WRDI    0x04
#define FRAM_RDSR    0x05
#define FRAM_WRSR    0x01
#define FRAM_READ    0x03
#define FRAM_WRITE   0x02
#define FRAM_RDID    0x9f
#define FRAM_SR_WPEN 0x80
#define FRAM_SR_BP0  0x08
#define FRAM_SR_BP1  0x04
#define FRAM_SR_WEL  0x02
#define FRAM_NULL    0x00

#define FRAM_NUM_BYTES (8 * 1024) //8KBytes
#define FRAM_TEST_DATA (((testAddr+testDataSeed) * 0x53)&0xff)
#define FRAM_TEST_ERROR_INSERT 0 //set one bit in the ESHD_FRAM_TEST_ERROR_INSERT byte to intentionally induce write errors
#define FRAM_TEST_BLOCK_SIZE 512
#define FRAM_TEST_BLOCK_MASK ((FRAM_NUM_BYTES/FRAM_TEST_BLOCK_SIZE)-1)


void setSPI_FRAM_Handle(SPI_HandleTypeDef *pHandle);

void FRAM_init(void);

uint8_t FRAM_read8(uint16_t address);
void FRAM_write8(uint16_t address, uint8_t byte);
uint32_t FRAM_read32(uint16_t address);
void FRAM_write32(uint16_t address, uint32_t data);


#endif /* INC_FRAM_H_ */
