/*
 * circural_buffer.h
 *
 *  Created on: 18 kwi 2023
 *      Author: piotr
 */

#ifndef INC_CIRCURAL_BUFFER_H_
#define INC_CIRCURAL_BUFFER_H_

#define BUFFER_SIZE		400


typedef struct
{
	uint32_t data_uint[BUFFER_SIZE];
    uint32_t head;
    uint32_t size;
} circular_buffer_uint_t;

void circular_buffer_uint_init(circular_buffer_uint_t *buff);
void circular_buffer_push_uint(circular_buffer_uint_t *buff, uint32_t new_data);

#endif /* INC_CIRCURAL_BUFFER_H_ */
