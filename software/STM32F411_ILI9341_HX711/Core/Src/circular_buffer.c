/*
 * circular_buffer.c
 *
 *  Created on: 18 kwi 2023
 *      Author: piotr
 */

#include "main.h"
#include "circural_buffer.h"



void circular_buffer_average_init(circular_buffer_avg_t *buff)
{
	buff->head = 0;
	buff->size = BUFFER_SIZE_AVG;

	for (uint32_t i=0; i < buff->size; i++)
	{
		buff->data[i] = 0;
	}
}
void circular_buffer_median_init(circular_buffer_med_t *buff)
{
	buff->head = 0;
	buff->size = BUFFER_SIZE_MEDIAN;

	for (uint32_t i=0; i < buff->size; i++)
	{
		buff->data[i] = 0;
	}
}

void circular_buffer_push_median(circular_buffer_med_t *buff, int32_t new_data)
{
	buff->data[buff->head] = new_data;

	buff->head++;
	buff->head = buff->head % buff->size;
}
void circular_buffer_push_average(circular_buffer_avg_t *buff, uint32_t new_data)
{
	buff->data[buff->head] = new_data;

	buff->head++;
	buff->head = buff->head % buff->size;
}

