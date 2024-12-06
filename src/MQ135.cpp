/*	
	MQ135.cpp
	Created by Fergus Baker
	22 August 2020
	Released into the public domain.
	
	Based by the work done by Fergus Baker.
	Modified by Veronica Oviedo to work with a MQ135 Air Quality sensor
	31 July 2023 // thx Fergus
	
	
*/

#include "MQ135.h"
#include "Arduino.h"

float MQ135::readPpm() {
	return (float) _COEF_A0 * pow(
		readRs() / R0,
		_COEF_A1
	);
}

float MQ135::readRs() {
	return _LOAD_RES * readRsRL();
}

float MQ135::readRsRL() {
	float voltage = convertVoltage(
		analogRead(a_pin)
	);

	return (v_in - voltage) / voltage;
}

float MQ135::convertVoltage(int voltage) {
	// ATD conversion
	return (float) voltage * (v_in / 1023.0);
}

void MQ135::calibrate() {
	#ifndef _R0	// if no hardcoded R0 value

	for (int i = 0; i <= CALIBRATION_SECONDS; i++) {
		delay(1000);
		R0 = readRs() / _CALIBRATION_CONSTANT;
	}

	#endif		// end
}


float MQ135::getR0() {
	return R0;
}


