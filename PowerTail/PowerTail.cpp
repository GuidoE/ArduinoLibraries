/*
 * PowerTail.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: dgre420
 */
#include "Arduino.h"
#include "PowerTail.h"

PowerTail::PowerTail(int pin = A0, int led = 13) {

	powerPin = pin;
	ledPin = led;
	powerOn = false;

	incomingByte = 0;

	pinMode(ledPin, OUTPUT);
	pinMode(powerPin, OUTPUT);

	digitalWrite(ledPin, LOW);
	digitalWrite(powerPin, HIGH);
}

void PowerTail::Power() {
	if (Serial.available() > 0) {

		powerOn = !powerOn;

		if (powerOn) {
			digitalWrite(ledPin, HIGH);
			digitalWrite(powerPin, LOW);
			Serial.println("ON");
		} else {
			digitalWrite(ledPin, LOW);
			digitalWrite(powerPin, HIGH);
			Serial.println("OFF");
		}

		//read all the bytes in the serial buffer (we don't care about the contents of the data)
		while (Serial.available())
			incomingByte = Serial.read();
	}
}

void PowerTail::ManualPower() {
	powerOn = !powerOn;
	if (powerOn) {
		digitalWrite(ledPin, HIGH);
		digitalWrite(powerPin, LOW);
		Serial.println("PowerTail ON");
	} else {
		digitalWrite(ledPin, LOW);
		digitalWrite(powerPin, HIGH);
		Serial.println("PowerTail OFF");
	}
}
