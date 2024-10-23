//
// Created by Christoph Schmid on 05.02.24.
//
#include "controller.h"

enum direction {
    noButton = 0,
    rightClick = 1,
    rightHold = 2,
    leftClick = 3,
    leftHold = 4
};

void controller(uint8_t button) {
    static uint8_t currentButton = 0;
    static uint8_t nextButton = 0;
    static uint8_t cycleCount = 0;

    // active Period
    if(getActivePeriod()){
        // button not pressed - current button stays the same - skip
        // same button pressed - current button stays the same - skip
        // another button pressed - safe in buffer
        if(currentButton != button && button != noButton){
            nextButton = button;
        }
    }

    // non-active period
    if(!getActivePeriod()){
        // button 0 - skip
        // button not 0
        if(button != noButton) {
            currentButton = button;
        }
        // next button set, change direction
        if(nextButton!=noButton){
            currentButton = nextButton;
            // reset next button
            nextButton = noButton;
            // reset cycleCount
            cycleCount = cycleInit;
        }
    }

    switch(currentButton){
        case rightClick:
            // returns false if whole cycle done
            if(blinkPeriod(right) && cycleCount != cycles) {
                currentButton = rightClick;
            }
            // Count up to 3 so 3 cycles are done
            if(!getActivePeriod()) cycleCount++;
            // If 3 cycles done, current button = 0 and cycleCount reset.
            if(cycleCount == cycles) {
                cycleCount = cycleInit;
                currentButton = noButton;
            }
            break;
        case rightHold:
            // returns false if whole cycle done
            if(blinkPeriod(right)) currentButton = rightHold;
            else currentButton = noButton;
            break;
        case leftClick:
            // returns false if whole cycle done
            if(blinkPeriod(left) && cycleCount != cycles) {
                currentButton = leftClick;
            }
            // Count up to 3 so 3 cycles are done
            if(!getActivePeriod()) cycleCount++;
            // If 3 cycles done, current button = 0 and cycleCount reset.
            if(cycleCount == cycles) {
                cycleCount = cycleInit;
                currentButton = noButton;
            }
            break;
        case leftHold:
            // returns false if whole cycle done
            if(blinkPeriod(left)) currentButton = leftHold;
            else currentButton = noButton;
            break;
        default:
            break;
    }
}
