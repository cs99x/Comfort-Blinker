/*
 * controller.h
 *
 *  Created on: Feb 7, 2024
 *      Author: csuser
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_
#include "main.h"
#include "ledDriver.h"
#include <stdint.h>
#include <stdbool.h>
#define right true
#define left false
#define cycles 3
#define cycleInit 0
void controller(uint8_t direction);
#endif /* INC_CONTROLLER_H_ */
