#include <Keyboard.h>  // Include the required libraries for this project
#include <HID_Buttons.h>

const uint8_t ButtonPin1 = 4; // Assigns buttons to pins on the Arduino board
const uint8_t ButtonPin2 = 5;
const uint8_t ButtonPin3 = 6;
const uint8_t ButtonPin4 = 7;
const uint8_t ButtonPin5 = 8;

const uint8_t Key1 = 'w'; // Assigns keyboard keys to buttons
const uint8_t Key2 = 's';
const uint8_t Key3 = 'a';
const uint8_t Key4 = 'd';
const uint8_t Key5 = 'x';

KeyboardButton Button1(Key1); // Creates a relationship between buttons and keyboard keys
KeyboardButton Button2(Key2);
KeyboardButton Button3(Key3);
KeyboardButton Button4(Key4);
KeyboardButton Button5(Key5);

void setup() {
  pinMode(ButtonPin1, INPUT_PULLUP);  // Sets Arduino button pins as inputs
  pinMode(ButtonPin2, INPUT_PULLUP);
  pinMode(ButtonPin3, INPUT_PULLUP);
  pinMode(ButtonPin4, INPUT_PULLUP);
  pinMode(ButtonPin5, INPUT_PULLUP);

  Keyboard.begin(); // Causes the Arduino to emulate a keyboard for the connected computer
}

void loop() {
  boolean pressed1 = !digitalRead(ButtonPin1); // Checks if buttons are pressed or released
  boolean pressed2 = !digitalRead(ButtonPin2);
  boolean pressed3 = !digitalRead(ButtonPin3);
  boolean pressed4 = !digitalRead(ButtonPin4);
  boolean pressed5 = !digitalRead(ButtonPin5);

  Button1.set(pressed1); // If a button was pressed or released, send the corresponding keystroke to the computer
  Button2.set(pressed2);
  Button3.set(pressed3);
  Button4.set(pressed4);
  Button5.set(pressed5);
}
