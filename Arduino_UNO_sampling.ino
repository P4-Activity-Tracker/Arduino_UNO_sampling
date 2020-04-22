#include "TimerOne.h"

#define number_of_channels 1

boolean runADC = false;
unsigned int counter = 0;
uint8_t channels[number_of_channels] = {A0};//,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15};
int sensorValue[number_of_channels];

void setup() {
  Serial.begin(115200);               // initialize serial communication at 115200 bits per second:
}

void TimerIsr() {
    runADC = true;
}

void loop() {
  if (runADC) {
    runADC = false;  
    for (int i = 0; i < number_of_channels; i++) {
      sensorValue[i] = analogRead(channels[i]);   
    }
    for (int i = 0; i < number_of_channels; i++) {
        Serial.write(sensorValue[i]);
        Serial.write(sensorValue[i]>>8);
    }
  }
}