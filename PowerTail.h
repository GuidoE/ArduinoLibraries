/*
 * PowerTail.h
 *
 *  Created on: Aug 23, 2015
 *      Author: dgre420
 */

#ifndef POWERTAIL_H_
#define POWERTAIL_H_
#include "Arduino.h"

class PowerTail {

public:
	PowerTail(int pin, int led);

	// control powerSocket
	int powerPin;
	int ledPin;
	boolean powerOn;

	// control LEDs

	int incomingByte;  //a variable to read incoming serial data

	void Power();
	void ManualPower();
	void TurnOn();
	void TurnOff();
};


#endif /* POWERTAIL_H_ */
