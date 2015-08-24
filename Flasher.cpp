/*
 * Flasher.cpp
 *
 *  Created on: Aug 23, 2015
 *      Author: dgre420
 */

// Do not remove the include below
#include "Flasher.h"
#include "Arduino.h"

Flasher::Flasher(int pin, long on, long off) {
	ledPin = pin;
	pinMode(ledPin, OUTPUT);

	OnTime = on;
	OffTime = off;

	ledState = LOW;
	previousMillis = 0;
}

void Flasher::Update() {
	// check to see if it's time to change the state of the LED
	unsigned long currentMillis = millis();

	if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime)) {
		ledState = LOW;  // Turn it off
		previousMillis = currentMillis;  // Remember the time
		digitalWrite(ledPin, ledState);  // Update the actual LED
	} else if ((ledState == LOW)
			&& (currentMillis - previousMillis >= OffTime)) {
		ledState = HIGH;  // turn it on
		previousMillis = currentMillis;   // Remember the time
		digitalWrite(ledPin, ledState);   // Update the actual LED
	}
}

Flasher led1(13, 750, 350);

/*void setup() {
	Serial.begin(9600);
}

void loop() {
	led1.Update();
}*/
