/*
 * PIR.h
 *
 *  Created on: Aug 23, 2015
 *      Author: dgre420
 */

#ifndef PIR_H_
#define PIR_H_
#include "Arduino.h"

class PIR {

public:
	PIR(int pin, int led, int calibration);
	PIR(int pin, int led, int calibration, long unsigned int pauseInterval);
	int pirPin;
	int ledPin;

	int calibrationTime;

	//the time when the sensor outputs a low impulse
	long unsigned int lowIn;

	//the amount of milliseconds the sensor has to be low
	//before we assume all motion has stopped
	long unsigned int pause;

	boolean lockLow;
	boolean takeLowTime;

	boolean presence;


	void Motion();
};




#endif /* PIR_H_ */
