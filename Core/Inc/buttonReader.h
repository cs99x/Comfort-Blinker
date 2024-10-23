/*
 * buttonReader.h
 *
 *  Created on: Feb 7, 2024
 *      Author: csuser
 */

#ifndef INC_BUTTONREADER_H_
#define INC_BUTTONREADER_H_
#include "main.h"
#include <stdbool.h>
#include <stdint.h>

static bool debounceButton(GPIO_TypeDef* port, uint16_t pin);

uint8_t buttonReader();

#endif /* INC_BUTTONREADER_H_ */
