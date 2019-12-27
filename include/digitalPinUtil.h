#ifndef pinUtil_H
#define pinUtil_H

#include "wiring.h"

#define HIGH 1
#define LOW 0

#define OUTPUT 1
#define INPUT 0


namespace digitalPinUtil
{
    void digitalWritePin(uint8_t pin, uint8_t value){
        uint8_t bitMask = wiring::digitalPinToBitMask(pin);
        volatile uint8_t *out = wiring::portOutputRegister(port);

        if (val == LOW) {
            *out &= ~bitMask;
        } else {
            *out |= bitMask;
        }
    }

    void pinMode(uint8_t pin, uint8_t mode){
        switch(mode){
            case OUTPUT:
                *(wiring::portModeRegister(pin)) |= wiring::digitalPinToBitMask(pin);
                break;
            case INPUT:
                *(wiring::portModeRegister(pin)) &= ~wiring::digitalPinToBitMask(pin);
                break;
            default:
                break;
        }
    }
}
#endif