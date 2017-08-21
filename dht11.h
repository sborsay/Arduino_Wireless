/*####################################################################
 FILE: dht11.h - Library for the Virtuabotix DHT11 Sensor.
 VERSION: 2S0A

 PURPOSE: Measure and return temperature & Humidity. Additionally provides conversions.

 LICENSE: GPL v3 (http://www.gnu.org/licenses/gpl.html)
 GET UPDATES: https://www.virtuabotix.com/

      --##--##--##--##--##--##--##--##--##--##--
      ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##
      ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##
      | ##  ##  ##  ##  ##  ##  ##  ##  ##  ## |
      ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##
      ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##
      | ##  ##  ##  ##  ##  ##  ##  ##  ##  ## |
      ##  ##  ##  ## DHT11 SENSOR ##  ##  ##  ##
      ##  ##  ##  ##  ##FRONT ##  ##  ##  ##  ##
      | ##  ##  ##  ##  ##  ##  ##  ##  ##  ## |
      ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##
      ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##
      | ##  ##  ##  ##  ##  ##  ##  ##  ##  ## |
      ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##
      ##  ##  ##  ##  ##  ##  ##  ##  ##  ##  ##
      --##--##--##--##--##--##--##--##--##--##--
          ||       ||          || (Not    ||
          ||       ||          || Used)   ||
        VDD(5V)   Readout(I/O)          Ground

  HISTORY:
  Joseph Dattilo (Virtuabotix LLC) - Version 2S0A (27 May 12)
  -Rewritten to with more powerful Versalino functionality
  Joseph Dattilo (Virtuabotix LLC) - Version 0.4.5 (11/11/11)
  -Made Library Arduino 1.0 Compatible
  Joseph Dattilo (Virtuabotix LLC) - Version 0.4.0 (06/11/11)
  -Fixed bugs (squish)
  Mod by Rob Tillaart - Version 0.3 (28/03/2011)
  Mod by SimKard - Version 0.2 (24/11/2010)
 George Hadjikyriacou - Original version (??)
#######################################################################*/


#ifndef DHT11_H
#define DHT11_H
#define DHT11LIB_VERSION "2S0A"

#include <stddef.h>

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif


#include <Versalino.h>
#include <inttypes.h>


class dht11
{

	public:
	//-------Versalino Functions
	VersalinoBUS getBUS(); //This will return the VersalinoBUS currently assigned to the instance of this library
	void setBUS(VersalinoBUS myBUS);
	void removeBUS();

	//-------dht11 Functions
	dht11();//included for legacy compatability
    dht11(int pin);
    dht11(int pin, VersalinoBUS myBUS);

	void attach(int pin);//Attaches dht11 object to a particular sensorPin
	void attach(int pin, VersalinoBUS myBUS);//Attaches dht11 object to a particular sensorPin on a particular VersalinoBUS

	int read();//defaults to the attached pin
	int read(int pin);
	int read(int pin, VersalinoBUS myBUS);
	int humidity;
	int temperature;
	int celcius();
	double fahrenheit();
	double fahrenheit(double dCelcius);
	double kelvin();
	double kelvin(double dCelcius);
	double dewPoint();
	double dewPointFast();


	private:
	VersalinoBUS _myBUS;
	bool _BUSenabled;
	int _sensorPin;//defaults to pin 2

};


#endif // DHT11_H
