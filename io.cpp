#include <Arduino.h>
#include "io.h"


#define ACTIVE_HIGH 0
#define ACTIVE_LOW  1


led::led(int Adr, int mode) {
  pinMode(Adr, mode);
  pinAdr = Adr;
}


button::button(int Adr, int mode) {
  pinMode(Adr, mode);
  pinAdr = Adr;
}


pot::pot(int Adr, int mode, int adcBits, float vcc) {
  pinMode(Adr, mode);
  pinAdr = Adr;
  VCC = vcc;
  ADC_BITS = adcBits;
}


void led::on() {
  digitalWrite(pinAdr, HIGH);
}


void led::off() {
  digitalWrite(pinAdr, LOW);
}


void button::poll() {
  switch (trigger) {
    case ACTIVE_HIGH:
      state = digitalRead(pinAdr);
      break;
    case ACTIVE_LOW:
      state = !digitalRead(pinAdr);
      break;
  }
}


bool button::getState() {
  return state;
}


void button::invert() {
  switch (trigger) {
    case ACTIVE_HIGH:
      trigger = ACTIVE_LOW;
      break;
    case ACTIVE_LOW:
      trigger = ACTIVE_HIGH;
      break;
  }
}


float pot::getVoltage() {
  voltage = (analogRead(pinAdr) * VCC) / ADC_BITS;
  return voltage;
}


void invertTrigger(int num, ...) {
    va_list arguments;                     

    va_start (arguments, num);   
            
    for (int x = 0; x < num; x++) {
        va_arg (arguments, button*)->invert();
    }
    va_end (arguments);
}


void pollInputs(int num, ...) {
    va_list arguments;                     

    va_start (arguments, num);   
            
    for (int x = 0; x < num; x++) {
        va_arg (arguments, button*)->poll(); 
    }
    va_end (arguments);
}
