/*
 * circural_buffer.h
 *
 *  Created on: 18 kwi 2023
 *      Author: piotr
 */

#ifndef INC_CIRCURAL_BUFFER_H_
#define INC_CIRCURAL_BUFFER_H_

#define BUFFER_SIZE_AVG		100
#define BUFFER_SIZE_MEDIAN		25

typedef struct
{
	int32_t data[BUFFER_SIZE_MEDIAN];
    uint32_t head;
    uint32_t size;
} circular_buffer_med_t;


typedef struct
{
	uint32_t data[BUFFER_SIZE_AVG];
    uint32_t head;
    uint32_t size;
} circular_buffer_avg_t;

void circular_buffer_median_init(circular_buffer_med_t *buff);
void circular_buffer_average_init(circular_buffer_avg_t *buff);
void circular_buffer_push_median(circular_buffer_med_t *buff, int32_t new_data);
void circular_buffer_push_average(circular_buffer_avg_t *buff, uint32_t new_data);

#endif /* INC_CIRCURAL_BUFFER_H_ */
