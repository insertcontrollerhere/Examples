#include "Mouse.h" // Import the required librarires

const int upButton = 4; // Assigns buttons to pins on the Arduino board
const int downButton = 5;
const int leftButton = 6;
const int rightButton = 7;

int speedModifier = 1; // Setting that changes the speed of the mouse - higher numbers increase the speed, lower numbers decrease the speed

void setup() {
  pinMode(upButton, INPUT_PULLUP);  // Sets Arduino button pins as inputs
  pinMode(downButton, INPUT_PULLUP);
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(mouseButton, INPUT_PULLUP);
  
  Mouse.begin(); // Causes the Arduino to emulate a mouse for the connected computer
}

void loop() {
  int upState = digitalRead(upButton);  // Read the state of the buttons
  int downState = digitalRead(downButton);
  int rightState = digitalRead(rightButton);
  int leftState = digitalRead(leftButton);

  int  relative_x = (leftState - rightState) * speedModifier; // Determine the x/y coordinate changes relative to the current mouse position
  int  relative_y = (upState - downState) * speedModifier;

  if ((relative_x != 0) || (relative_y != 0)) { // Check if the relative x or y positions are non-zero
    Mouse.move(relative_x, relative_y, 0);  // Move the mouse relative to the button commands
  }
}
