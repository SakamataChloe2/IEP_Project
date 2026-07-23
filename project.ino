// Abel(SakamataChloe2), P2603281, DCPE/FT/1B/22, Introduction to Engineering Programming
// Rithik(Commie_Debug), P263, DCPE/FT/1B/22, Introduction to Engineering Programming

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
// The 2 outputs will continuously play until the issue is resolved (the user pushes a button). After which the program will go back to monitoring.

//Pins

//Functions

void setup() {


}

void loop() {
  //LDR loop for detecting change in light levels to figure out if an intruder has arrived, return a int val
  //Humidity loop for detecting a change in humidity, return a int val
  //Temperature loop for detecting a change in temperature, return a int val

  //Checker function to analyse wheter each of the preceding functions gave an abnormal value, if they did it will make a buzz(unique one) and a light to go off in a repeated loop that will only terminate once a button is pressed

}

//LDR loop 
void LDR_Monitor(){

}

//Humidity loop
void Humidity_Monitor(){

}

//Temperature loop
void Temperature_Monitor(){

}

//Lights Function
void Lights_Display(int LightCode){

}

//Buzzer Function
void Buzzer(int BuzzCode){

}

//Checker function
int Computation(int LDR_Val, int Humidity_Val, int Temp_Val){
  
}
