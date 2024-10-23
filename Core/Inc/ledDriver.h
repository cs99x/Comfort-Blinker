#ifndef INC_LEDDRIVER_H_
#define INC_LEDDRIVER_H_
#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#define delay 500

// Declaration of led struct
typedef struct {
	GPIO_TypeDef* port;
    uint16_t pin;
} gpioLeds;

bool blinkPeriod(bool direction);
void switchLed(gpioLeds led, bool state);
bool getActivePeriod();
uint8_t getStep();

#endif /* INC_LEDDRIVER_H_ */
