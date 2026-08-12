// Group 1
// Abel(SakamataChloe2), P2603281, DCPE/FT/1B/22, Introduction to Engineering Programming
// Rithik(Commie-debug), P2635239, DCPE/FT/1B/22, Introduction to Engineering Programming

//Description:
//3 Monitor/Input Functions that will run at the start of setup(). 
// Each of the functions checks a unique parameter (light levels, humidity, or temperature). T
// hey will take a reading and process it to see if it is high, low or normal. If it is low it will return a value of 1, if it is high it will return a value of 2, otherwise it returns a value of 0. 
// The exception is the LDR_Monitor which will only output a value of 1(Abnormal) or 0(Normal).

//1 Computational Function that will have the 3 outputs of the monitor functions will be its arguments.
// If any of the variables are 1 or 2 (or only 1 in the case of LDR_Val) it will call the output functions with a parameter that can be used to determine which of the 3 monitor functions is high, low or abnormal. 
// If there are no issues the program will go back to the beginning for monitoring.

//2 Output Functions that will either play a buzzer tone or flash the LED’s. 
// Using the argument from the computational function it can produce a unique output based on which of the monitors is abnormal. 
// The 2 outputs will continuously play until the issue is resolved (the user uses a remote to off it). After which the program will go back to monitoring.

//Libraries
#include "RichShieldDHT.h"
#include "RichShieldPassiveBuzzer.h"
#include <DHT.h>
#include <IRremote.hpp>


//Pins and threshold constants

const int PIN_LED_RED    = 4;
const int PIN_LED_GREEN  = 5;
const int PIN_LED_BLUE   = 6;
const int PIN_LED_YELLOW = 7;
const int PIN_KEY1       = 8;
const int PIN_KEY2       = 9;
const int PIN_BUZZER     = 3;
const int PIN_IR_RECV    = 2;
const int PIN_LDR        = A2;
const int PIN_NTC        = A1;
const int PIN_DHT11      = 12;

const float TEMP_LOW_C    = 18.0;   
const float TEMP_HIGH_C   = 28.0;   
const float HUMIDITY_LOW  = 30.0;   
const float HUMIDITY_HIGH = 70.0;   
const int   LDR_DARK_THRESHOLD   = 200;  
const int   LDR_BRIGHT_THRESHOLD = 850;  
const float NTC_NOMINAL_RES   = 10000.0; 
const float NTC_NOMINAL_TEMP  = 25.0;
const float NTC_BETA          = 3950.0;
const float NTC_SERIES_RES    = 10000.0; 


//Functions

void setup() {


}

void loop() {
  
  //LDR loop for detecting change in light levels to figure out if an intruder has arrived, return a int val
  //Humidity loop for detecting a change in humidity, return a int val
  //Temperature loop for detecting a change in temperature, return a int val

  //Checker function to analyse wheter each of the preceding functions gave an abnormal value, if they did it will make a buzz(unique one) and a light to go off in a repeated loop that will only terminate once a button is pressed

}

//LDR loop(SakamataChloe2)
int LDR_Monitor(){

}

//Humidity loop(Commie-debug)
int Humidity_Monitor(){

}

//Temperature loop(SakamataChloe2)
int Temperature_Monitor(){

}

//Lights Function(SakamataChloe2)
void High_Temp_Lights(){

}
void Low_Temp_Lights(){

}
void High_Humidity_Lights(){

}
void Low_Humidity_Lights(){

}
void Intruder_Alert_Red_Spy_In_The_Base(){

}


//Buzzer Function(Commie-debug)
void High_Temp_Buzzer(){

}
void Low_Temp_Buzzer(){

}
void High_Humidity_Buzzer(){

}
void Low_Humidity_Buzzer(){

}
void Intruder_Alert_Blue_Spy_In_The_Base(){

}




//Checker function(Commie-debug)
int Computation(int LDR_Val, int Humidity_Val, int Temp_Val){
  
}
