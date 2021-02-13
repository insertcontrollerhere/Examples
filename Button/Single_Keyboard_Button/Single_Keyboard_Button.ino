#include <Keyboard.h> // Import the required librarires - the Keyboard.h library MUST be included before HID_Buttons.h
#include <HID_Buttons.h>

const uint8_t ButtonPin = 4; // The button is assigned to pin 4 on the Arduino

const uint8_t Key = 'w'; // Assign the keystroke "w"

KeyboardButton myButton(Key); // Use the KeyboardButton function from the library to assign the "w" key to the button

void setup() {
  pinMode(ButtonPin, INPUT_PULLUP); // Set pin 4 to be in input
  Keyboard.begin(); // Tell the Arduino to start emulating a keyboard
}

void loop() {
  boolean pressed = !digitalRead(ButtonPin); // Check the current state of the button
  myButton.set(pressed); // Send the corresponding keystroke action based on the button state
}
