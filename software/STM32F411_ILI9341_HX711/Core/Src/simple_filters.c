/*
 * simple_filters.c
 *
 *  Created on: Apr 12, 2023
 *      Author: piotr
 */

#include "main.h"
#include "simple_filters.h"

circular_buffer_uint_t buffer_uint;

static uint32_t average_uint(uint32_t *array, uint32_t size);

void filter_moving_average_init(void)
{
	circular_buffer_uint_init(&buffer_uint);
}



uint32_t filter_moving_average_uint(uint32_t new_data)
{
   uint32_t out = 0;

   circular_buffer_push_uint(&buffer_uint, new_data);
   out = average_uint(buffer_uint.data_uint, buffer_uint.size);

   return out;
}

static uint32_t average_uint(uint32_t *array, uint32_t size)
{
	uint64_t sum = 0;

	for (uint32_t i = 0; i < size; i++)
	{
	  sum += array[i];
	}

	return (sum/size);
}
