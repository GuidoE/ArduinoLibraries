#include "Arduino.h"
#include "PIR.h"

PIR::PIR(int pin=7, int led=13, int calibration=10) {
	pirPin = pin;
	ledPin = led;
	calibrationTime = calibration;
	pause = 5000;
	lockLow = true;
	pinMode(pirPin, INPUT);
	pinMode(ledPin, OUTPUT);
	digitalWrite(pirPin, LOW);
	presence = false;
};

/*PIR::PIR(int pin=7, int led=13, int calibration=30, unsigned long int pauseInterval=5000) {
	pirPin = pin;
	ledPin = led;
	calibrationTime = calibration;
	pause = pauseInterval;
	lockLow = true;
	pinMode(pirPin, INPUT);
	pinMode(ledPin, OUTPUT);
	digitalWrite(pirPin, LOW);
};*/

void PIR::Motion() {
	if (digitalRead(pirPin) == HIGH) {
		digitalWrite(ledPin, HIGH); //the led visualizes the sensors output pin state
		if (lockLow) {
			//makes sure we wait for a transition to LOW before any further output is made:
			lockLow = false;
	        Serial.println("---");
	        Serial.print("motion detected at ");
	        Serial.print(millis()/1000);
	        Serial.println(" seconds");
	        presence = true;
		}
		takeLowTime = true;
	}

	if (digitalRead(pirPin) == LOW) {
		digitalWrite(ledPin, LOW); //the led visualizes the sensors output pin state
		if (takeLowTime) {
			lowIn = millis(); //save the time of the transition from high to LOW
			takeLowTime = false; //make sure this is only done at the start of a LOW phase
		}
		//if the sensor is low for more than the given pause,
		//we assume that no more motion is going to happen
		if (!lockLow && millis() - lowIn > pause) {
			//makes sure this block of code is only executed again after
			//a new motion sequence has been detected
			lockLow = true;
			Serial.print("motion ended at ");      //output
			Serial.print((millis() - pause)/1000);
			Serial.println(" seconds");
			presence = false;
		}
	}

}
;
