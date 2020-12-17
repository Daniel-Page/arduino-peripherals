#include <Arduino.h>
#include "msg.h"
#include "io.h"


void msg::init() {
  Serial.begin(9600);
}


void msg::stageBut(int num, ...) {
  int butState;
  va_list arguments;                     
  
  va_start (arguments, num);   
          
  for (int x = 0; x < num; x++) {
      butState = (butState << 1) | va_arg (arguments, button*)->getState();
  }
  va_end (arguments);

  messageString += "butState";
  messageString += ",";
  messageString += butState;
  messageString += ";";
}


void msg::stagePot(int num, ...) {
  float potVoltage;
  va_list arguments;                     
  
  va_start (arguments, num);   
          
  for (int x = 0; x < num; x++) {
      potVoltage = va_arg (arguments, pot*)->getVoltage();
  }
  va_end (arguments);
  
  messageString += "potVoltage";
  messageString += ",";
  messageString += String(potVoltage, 1);
  messageString += ";";
}


void msg::transmit() {
  Serial.println(messageString);
  messageString = "";
}
