/* 
 *  Flying Broomstick Simulation Arduino Controller
 */


#include "io.h"
#include "msg.h"
#include "defs.h" // Must be last include


// Class object initialisations
led RedLED(RED_LED_PIN_ADR, OUTPUT);
led BlueLED(BLUE_LED_PIN_ADR, OUTPUT);
button RedButton(RED_BUT_PIN_ADR, INPUT_PULLUP);
button BlueButton(BLUE_BUT_PIN_ADR, INPUT_PULLUP);
pot Pot(POT_PIN_ADR, INPUT, ADC_BITS, VCC);

msg Message;


void setup() {
  Message.init(); // Has to be in setup
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

  Message.stageBut(2, &RedButton, &BlueButton); // Converts all possible input states into a unique number
  Message.stagePot(1, &Pot);
  Message.transmit(); // Send composed message via serial and reset buffer
}
