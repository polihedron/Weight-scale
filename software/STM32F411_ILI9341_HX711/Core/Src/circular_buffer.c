/*
 * circular_buffer.c
 *
 *  Created on: 18 kwi 2023
 *      Author: piotr
 */

#include "main.h"
#include "circural_buffer.h"

void circular_buffer_uint_init(circular_buffer_uint_t *buff)
{
	buff->head = 0;
	buff->size = BUFFER_SIZE;

	for (uint32_t i=0; i < buff->size; i++)
	{
		buff->data_uint[i] = 0;
	}
}


void circular_buffer_push_uint(circular_buffer_uint_t *buff, uint32_t new_data)
{
	buff->data_uint[buff->head] = new_data;

	buff->head++;
	buff->head = buff->head % buff->size;
}
