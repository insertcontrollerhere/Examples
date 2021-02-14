#include <Keyboard.h> // Include the required libraries for this project
#include <HID_Buttons.h>

const uint8_t X_AxisPin = A0;  // Analog pin for the joystick horizontal x-axis
const uint8_t Y_AxisPin = A1;  // Analog pin for the joystick horizontal y-axis


const int JoystickCenter   = 1023 / 2;  // The center value of the potentiometer reading (maximum analog reading of the potentiometer divided in half to find the center)
const int JoystickDeadzone = 50;  // Sets the deadzone for the joystick (any readings +/- the value of this setting from the center will be ignored)

KeyboardButton moveForward('w'); // Creates a relationship between the joystick and the keystrokes
KeyboardButton moveLeft('a');
KeyboardButton moveBackward('s');
KeyboardButton moveRight('d');

void setup() {
  Keyboard.begin(); // Causes the Arduino to emulate a keyboard for the connected computer
}

void loop() {
  int x = analogRead(X_AxisPin);  // Read the x-axis position
  int y = analogRead(Y_AxisPin);  // Read the y-axis position

  moveLeft.set(x < JoyCenter - JoyDeadzone);  // If the joystick value exceeds the the deadzone value in a given direction, press the coresponding directional key
  moveRight.set(x > JoyCenter + JoyDeadzone);
  moveForward.set(y < JoyCenter - JoyDeadzone);
  moveBackward.set(y > JoyCenter + JoyDeadzone);
}
