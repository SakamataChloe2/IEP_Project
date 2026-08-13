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
// The 2 outputs will continuously play until the issue is resolved (the user uses a remote to off it). After which the program will go back to monitoring. (It will be repeating while inside of the Computation Loop)

//Libraries
#include "RichShieldDHT.h"
#include "RichShieldPassiveBuzzer.h"
#include "RichShieldTM1637.h"
#include "RichShieldIRremote.h"
#include "RichShieldNTC.h"
#include <Wire.h>


//Pins and threshold constants
const int PIN_LED_RED = 4;
const int PIN_LED_GREEN = 5;
const int PIN_LED_BLUE = 6;
const int PIN_LED_YELLOW = 7;
const int PIN_KEY1 = 8;
const int PIN_KEY2 = 9;
const int PIN_BUZZER = 3;
const int PIN_IR_RECV = 2;
const int PIN_LDR = A2;
const int PIN_NTC = A1;
const int PIN_DHT11 = 12;

//Example values for thresholds
const float TEMP_LOW_C = 18.0;   
const float TEMP_HIGH_C = 28.0;   
const float HUMIDITY_LOW = 30.0;   
const float HUMIDITY_HIGH = 70.0;   
const int LDR_DARK_THRESHOLD = 200;  
const int LDR_BRIGHT_THRESHOLD = 850;  
const float NTC_NOMINAL_RES = 10000.0; 
const float NTC_NOMINAL_TEMP = 25.0;
const float NTC_BETA = 3950.0;
const float NTC_SERIES_RES = 10000.0; 

IRrecv IR(PIN_IR_RECV);


//Functions
void setup() {
  Serial.begin(9600); 
  
  dht.begin();
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
}

void loop() {
  int LDRVal, HUMVal, TEMPVal;

  LDRVal = LDR_Monitor();
  HUMVal = Humidity_Monitor();
  TEMPVal = Temperature_Monitor();
  Computation(LDRVal, HUMVal, TEMPVal);

  //LDR loop for detecting change in light levels to figure out if an intruder has arrived, return a int val
  //Humidity loop for detecting a change in humidity, return a int val
  //Temperature loop for detecting a change in temperature, return a int val

  //Checker function to analyse wheter each of the preceding functions gave an abnormal value, if they did it will make a buzz(unique one) and a light to go off in a repeated loop that will only terminate once a button is pressed

}

//LDR loop(SakamataChloe2)
int LDR_Monitor(){
  int i;
  float Total, Avg;
  Total = 0;
  float TempVals[3];

  for(i=0;i<3;i++){
     LDR_Vals[i] = analogRead(PIN_LDR);
     delay(250);
     Total += LDR_Vals[i];
  }
  Avg = Total/3;

  if (Avg < LDR_BRIGHT_THRESHOLD){
    return 1;
  }
  else{
    if (Avg > LDR_BRIGHT_THRESHOLD){
      return 0;
    }
  }
}

//Humidity loop(Commie-debug)
int Humidity_Monitor(){
  int i;
  float Total, Avg;
  Total = 0;
  float HumVals[3];

  for(i=0;i<3;i++){
     HumVals[i] = dht.readHumidity();
     delay(250);
     Total += HumVals[i];
  }
  Avg = Total/3;

  if (Avg < HUMIDITY_LOW){
    return 1;
  }
  else{
    if (Avg > HUMIDITY_HIGH){
      return 2;
    }
    else{
      return 0;
    }
  }
}

//Temperature loop(SakamataChloe2)
int Temperature_Monitor(){ //similiar to humdity code?
   int i;
  float Total, Avg;
  Total = 0;
  float TempVals[3];

  for(i=0;i<3;i++){
     TempVals[i] = analogRead(PIN_NTC);
     delay(250);
     Total += TempVals[i];
  }
  Avg = Total/3;

  if (Avg < TEMP_LOW_C){
    return 1;
  }
  else{
    if (Avg > TEMP_HIGH_C){
      return 2;
    }
    else{
      return 0;
    }
  }
}

//Lights Function(SakamataChloe2)
void High_Temp_Lights(){ //blink blink or no blink blink
   digitalWrite(PIN_LED_YELLOW, HIGH);
   delay(250);
   digitalWrite(PIN_LED_YELLOW, LOW);
   delay(250);
}
void Low_Temp_Lights(){
   digitalWrite(PIN_LED_GREEN, HIGH);
   delay(250);
   digitalWrite(PIN_LED_GREEN, LOW);
   delay(250);
}
void High_Humidity_Lights(){
   digitalWrite(PIN_LED_BLUE, HIGH);
   delay(250);
   digitalWrite(PIN_LED_BLUE, LOW);
   delay(250);
}
void Low_Humidity_Lights(){
   digitalWrite(PIN_LED_RED, HIGH);
   delay(250);
   digitalWrite(PIN_LED_RED, LOW);
   delay(250);
}
void Intruder_Alert_Red_Spy_In_The_Base(){
   digitalWrite(PIN_LED_RED, HIGH);
   digitalWrite(PIN_LED_BLUE, HIGH);
   digitalWrite(PIN_LED_GREEN, HIGH); 
   digitalWrite(PIN_LED_YELLOW, HIGH);
   delay(250);
   digitalWrite(PIN_LED_RED, LOW);
   digitalWrite(PIN_LED_BLUE, LOW);
   digitalWrite(PIN_LED_GREEN, LOW);
   digitalWrite(PIN_LED_YELLOW, LOW);
   delay(250);
}


//Buzzer Function(Commie-debug)
void High_Temp_Buzzer(){
  tone(PIN_BUZZER, 1500, 200); 
  delay(250);
  tone(PIN_BUZZER, 1000, 200); 
  delay(250);
}
void Low_Temp_Buzzer(){
  tone(PIN_BUZZER, 400, 400); 
  delay(450);
  tone(PIN_BUZZER, 300, 400); 
  delay(450);
  tone(PIN_BUZZER, 200, 800); 
  delay(850);
}
void High_Humidity_Buzzer(){
  tone(PIN_BUZZER, 600, 100); delay(120);
  tone(PIN_BUZZER, 800, 100); delay(120);
  tone(PIN_BUZZER, 1000, 100); delay(120);
  tone(PIN_BUZZER, 1200, 300); delay(400);
}
void Low_Humidity_Buzzer(){
  tone(PIN_BUZZER, 2500, 30); 
  delay(400);
}
void Intruder_Alert_Blue_Spy_In_The_Base(){
  tone(PIN_BUZZER, 1200, 150); 
  delay(150);
  tone(PIN_BUZZER, 700, 150);  
  delay(150);
}


//Checker function(Commie-debug)
int Computation(int LDR_Val, int Humidity_Val, int Temp_Val){
  int Abnormal = 0;
  
  //LDR_Val_Check
  if ((LDR_Val == 1) or (Humidity_Val == 1) or (Humidity_Val == 2) or (Temp_Val == 1) or (Temp_Val == 2)){
    Abnormal = 1;
  }

  while (Abnormal == 1) {
    //Buzzers & Lights
    if (LDR_Val == 1){
      Intruder_Alert_Red_Spy_In_The_Base();
      Intruder_Alert_Blue_Spy_In_The_Base();
    }
    
    if (Humidity_Val == 1){
      Low_Humidity_Lights();
      Low_Humidity_Buzzer();
    }
    else{
      if (Humidity_Val == 2){
        High_Humidity_Lights();
        High_Humidity_Buzzer();
      }
    }

    if (Temp_Val == 1){
      Low_Temp_Lights();
      Low_Temp_Buzzer();
    }
    else{
      if (Temp_Val == 2){
        High_Temp_Lights();
        High_Temp_Buzzer();
      }
    }
    
    if (IR.decode()) {
      IR.resume();
      Abnormal = 0;  
    }
  }
  
  return 0; //Return to the main loop once resolved
  
}
