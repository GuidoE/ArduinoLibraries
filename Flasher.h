/*
 * Flasher.h
 *
 *  Created on: Aug 23, 2015
 *      Author: dgre420
 */

#ifndef FLASHER_H_
#define FLASHER_H_
#include "Arduino.h"
//add your includes for the project ClosetController here

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project ClosetController here

class Flasher {

public:
	Flasher(int pin, long on, long off);
	// Class Member Variables
	// These are initialized at startup
	int ledPin;      // the number of the LED pin
	long OnTime;     // milliseconds of on-time
	long OffTime;    // milliseconds of off-time

	// These maintain the current state
	int ledState;                 // ledState used to set the LED
	unsigned long previousMillis;   // will store last time LED was updated

	// Constructor - creates a Flasher
	// and initializes the member variables and state
	void Update();
};

#endif /* FLASHER_H_ */
