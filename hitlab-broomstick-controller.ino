/* 
 *  Broomstick VR Experience Project
 *  HIT Lab NZ
 */


#include "io.h"
#include "defs.h"


// Class object initialisations
led RedLED(RED_LED_PIN_ADR, OUTPUT);
led BlueLED(BLUE_LED_PIN_ADR, OUTPUT);
button RedButton(RED_BUT_PIN_ADR, INPUT_PULLUP);
button BlueButton(BLUE_BUT_PIN_ADR, INPUT_PULLUP);
pot Pot(POT_PIN_ADR, INPUT, ADC_BITS, VCC);


void setup() {
  Serial.begin(9600);
  invertTrigger(2, &RedButton, &BlueButton); // Swaps between active high and active low
}


void loop() {
  pollInputs(2, &RedButton, &BlueButton); // Updates the state variables for inputs

  if (RedButton.getState()) {
    RedLED.on(); 
  } else {
    RedLED.off();
  }
  
  if (BlueButton.getState()) {
    BlueLED.on();
  } else {
    BlueLED.off();
  }
  
  int state = statesToNumber(2, &RedButton, &BlueButton); // Converts all possible input states into a unique number
  Serial.print("state,");
  Serial.println(state);

  Serial.print("pot,");
  Serial.println(Pot.getVoltage());
  
  delay(10);
}
