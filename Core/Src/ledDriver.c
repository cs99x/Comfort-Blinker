#include "ledDriver.h"

// Definition of LEDs
gpioLeds leds[5] = {
	{LED1_GPIO_Port, LED1_Pin},
	{LED2_GPIO_Port, LED2_Pin},
	{LED3_GPIO_Port, LED3_Pin},
	{LED4_GPIO_Port, LED4_Pin},
	{LED5_GPIO_Port, LED5_Pin},
};

// Count members of struct
uint8_t  ledCount = sizeof(leds) / sizeof(leds[0]);

enum Step {
	step0 = 0,
    step1 = 1,
    step2 = 2,
    step3 = 3,
    step4 = 4,
    step5 = 5,
	step6 = 6,
};

uint8_t currentStep = step0;
bool activePeriod = false;

bool blinkPeriod(bool direction){
    static uint32_t lastTime = 0; // Store the last time you checked
    static uint8_t step = step1;
    uint32_t currentTime = HAL_GetTick(); // Get current time

    // Time not elapsed
    if ((currentTime - lastTime) < delay) return (true);

    // Update last time after 1 second has elapsed
    lastTime = currentTime;

    switch(step){
        case step1:
            direction ? switchLed(leds[0], true) : switchLed(leds[4], true);
            step = step2;
            break;
        case step2:
            direction ? switchLed(leds[1], true) : switchLed(leds[3], true);
            step = step3;
            break;
        case step3:
            direction ? switchLed(leds[2], true) : switchLed(leds[2], true);
            step = step4;
            break;
        case step4:
            direction ? switchLed(leds[3], true) : switchLed(leds[1], true);
            step = step5;
            break;
        case step5:
            direction ? switchLed(leds[4], true) : switchLed(leds[0], true);
            step = step6;
            break;
        case step6:
        	for(uint8_t i = 0; i < ledCount; i++) switchLed(leds[i], false);
			step = step1;
			activePeriod = false;
			return (false);
        default:
            break;
    }
    currentStep = step;
    activePeriod = true;
    return (true);
}

bool getActivePeriod(){
    return (activePeriod);
}

uint8_t getStep(){
    return (currentStep);
}

void switchLed(gpioLeds led, bool state){
	HAL_GPIO_WritePin(led.port, led.pin, state);
}
