#include "buttonReader.h"

#define DEBOUNCE_TIME 50
#define LONG_PRESS_TIME 200

enum ButtonAction {
    noAction = 0,
    rightClick = 1,
    rightHold = 2,
    leftClick = 3,
    leftHold = 4
};

typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
} gpioButtons;

gpioButtons buttons[2] = {
        {rightBlink_GPIO_Port, rightBlink_Pin},
        {leftBlink_GPIO_Port, leftBlink_Pin},
};

uint8_t buttonReader() {
    static uint8_t oldButton = 0;

	if (debounceButton(buttons[0].port, buttons[0].pin)) {
        uint32_t pressTime = HAL_GetTick();
        while (HAL_GPIO_ReadPin(buttons[0].port, buttons[0].pin) == false) {
            if ((HAL_GetTick() - pressTime) > LONG_PRESS_TIME) {
                return rightHold;
            }
        }
        return rightClick;
    }

    if (debounceButton(buttons[1].port, buttons[1].pin)) {
        uint32_t pressTime = HAL_GetTick();
        while (HAL_GPIO_ReadPin(buttons[1].port, buttons[1].pin) == false) {
            if ((HAL_GetTick() - pressTime) > LONG_PRESS_TIME) {
                return leftClick;
            }
        }
        return leftHold;
    }

    return noAction;
}


static bool debounceButton(GPIO_TypeDef* port, uint16_t pin) {
    if (HAL_GPIO_ReadPin(port, pin) == false) {
        uint32_t pressTime = HAL_GetTick();
        if (HAL_GetTick() - pressTime < DEBOUNCE_TIME) {
            if (HAL_GPIO_ReadPin(port, pin) != false) {
                return 0;
            }
        }
        return true;
    }
    return false;
}
