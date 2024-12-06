/*	
	MQ4_Example.ino

	Example sketch for MQ4 methane detector.
		- connect analog input 
		- set A_PIN to the relevant pin
		- connect device ground to GND pin 
		- device VC to 5.0 volts

	Created by Fergus Baker
	22 August 2020
	Released into the public domain.
*/


#include "MQ4.h"

#define A_PIN 36
#define VOLTAGE 5

// init MQ7 device
MQ4 mq4(A_PIN, VOLTAGE);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial connection
  }

  Serial.println("");  // blank new line

  Serial.println("Calibrating MQ4");
  mq4.calibrate();  // calculates R0
  Serial.println("Calibration done!");
}

void loop() {
  Serial.print("PPM = ");
  Serial.println(mq4.readPpm());

  Serial.println("");  // blank new line
  delay(1000);
}
