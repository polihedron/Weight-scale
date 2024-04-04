/*
 * simple_filters.c
 *
 *  Created on: Apr 12, 2023
 *      Author: piotr
 */
#include "string.h"
#include "main.h"
#include "simple_filters.h"

circular_buffer_med_t buffer_median;
circular_buffer_avg_t buffer_average;

static uint32_t average(uint32_t *array, uint32_t size);
static void bubble_sort(int32_t *array, int32_t size);
static void swap(int32_t *xp, int32_t *yp);
int32_t get_median(int32_t *array, int32_t size);

void filter_moving_average_init(void)
{
	circular_buffer_average_init(&buffer_average);
}


uint32_t filter_moving_average(uint32_t new_data)
{
   uint32_t out = 0;

   circular_buffer_push_average(&buffer_average, new_data);
   out = average(buffer_average.data, buffer_average.size);

   return out;
}

static uint32_t average(uint32_t *array, uint32_t size)
{
	uint64_t sum = 0;

	for (uint32_t i = 0; i < size; i++)
	{
	  sum += array[i];
	}

	return (sum/size);
}

void filter_median_init(void)
{
	circular_buffer_median_init(&buffer_median);
}

int32_t filter_median(int32_t new_data)
{
	int32_t tmp_array[BUFFER_SIZE_MEDIAN];
	int32_t out = 0;

	circular_buffer_push_median(&buffer_median, new_data);

	memcpy(tmp_array, buffer_median.data, sizeof(tmp_array));
	bubble_sort(tmp_array, BUFFER_SIZE_MEDIAN);

	out = get_median(tmp_array, BUFFER_SIZE_MEDIAN);

	return out;
}

static void bubble_sort(int32_t *array, int32_t size)
{
	uint32_t i, j;

    for (i = 0; i < (size - 1); i++)
	{
        for (j = 0; j < (size - i - 1); j++)
		{
            if (array[j] > array[j + 1])
			{
                swap(&array[j], &array[j + 1]);
			}
		}
	}
}

static void swap(int32_t *xp, int32_t *yp)
{
    int32_t temp = *xp;

    *xp = *yp;
    *yp = temp;
}

int32_t get_median(int32_t *array, int32_t size)
{
	int32_t median;

	if ((size % 2) == 0)
	{
		median = (array[size/2-1] + array[size/2]) / 2;
	}
	else
	{
		median = array[size/2-1];
	}

	return median;
}
