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
			TurnOn();
		} else {
			TurnOff();
		}

		//read all the bytes in the serial buffer (we don't care about the contents of the data)
		while (Serial.available())
			incomingByte = Serial.read();
	}
}

void PowerTail::ManualPower() {
	if (digitalRead(powerPin) == LOW) {
		TurnOff();
	} else {
		TurnOn();
	}
}

void PowerTail::TurnOn() {
	digitalWrite(powerPin, LOW);
	digitalWrite(ledPin, HIGH);
	Serial.println("PowerTail ON");
}

void PowerTail::TurnOff() {
	digitalWrite(powerPin, HIGH);
	digitalWrite(ledPin, LOW);
	Serial.println("PowerTail OFF");
}
