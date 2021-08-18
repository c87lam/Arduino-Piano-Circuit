/*
Arduino Keypad Piano Circuit

This arduino circuit functions as a piano; however, the keypad is used
as an input of the piano with the piezo buzzer being the output. Each keys
would play a note with a different frequency. The frequencies of each key
is based off a piano note.

The circuit:
* (1) x Arduno Uno R3
* (1) x 4x4 Keypad
* (1) x Piezo Buzzer
* (10) x Wires

Created in January 18, 2021
By Collin Lam

*/

//Include Keypad Library
#include <Keypad.h>

//Initialize Pins for Keypad Module and Piezo Buzzer
const byte ROWS = 4; 
const byte COLS = 4; 
const int piezo = 11; 
const int sound = 13; 

//initialize frequency notes array
int notes[] = {130, 138, 146, 155, 164, 174, 185, 196, 207,
               220, 233, 247, 261, 277, 303, 311};

//initialize the duration
const int duration = 200;
               
//Define the symbols used for the keypad
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Define the pins for column and row of the keypad
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

//initialize an instance of class myKypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup()
{
  //assign piezo buzzer as an output
  pinMode(piezo, OUTPUT); 
  
  //start the serial communication at 9600ms
  Serial.begin(9600); 
}

void loop()
{
  //runs the speaker function
  speaker();
  
  //delay for 100ms
  delay(100);
  
}

void speaker()
{
  //initalize customKey
  char customKey = customKeypad.getKey();
  
  //play a sound if a button is pressed with respect to the tone arrays
  if(customKey == '1'){
    tone(sound, notes[0], duration);
  } else if(customKey == '2'){
    tone(sound,notes[1], duration);
  } else if(customKey == '3'){
    tone(sound, notes[2], duration);
  } else if(customKey == 'A'){
    tone(sound, notes[3], duration);
  } else if(customKey == '4'){
    tone(sound, notes[4], duration);
  } else if(customKey == '5'){
    tone(sound, notes[5], duration);
  } else if(customKey == '6'){
    tone(sound, notes[6], duration);
  } else if(customKey == 'B'){
    tone(sound, notes[7], duration);
  } else if(customKey == '7'){
    tone(sound, notes[8], duration);
  } else if(customKey == '8'){
    tone(sound, notes[9], duration);
  } else if(customKey == '9'){
    tone(sound, notes[10], duration);
  } else if(customKey == 'C'){
    tone(sound, notes[11], duration);
  } else if(customKey == '*'){
    tone(sound, notes[12], duration);
  } else if(customKey == '0'){
    tone(sound, notes[13], duration);
  } else if(customKey == '#'){
    tone(sound, notes[14], duration);
  } else if(customKey == 'D'){
    tone(sound, notes[15], duration);
  } 
}
