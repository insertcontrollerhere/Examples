#include <Wire.h> // Import required libraries
#include <I2Cdev.h>
#include <MPU6050.h>
#include <Keyboard.h>

MPU6050 mpu; // Initialize MPU

int16_t ax, ay, az, gx, gy, gz; // Used to collect the accelerometer data - ax for x-axis, ay for y-axis, az for z-axis

int old_ax = 0; // Stores the accelerometer data from the previous loop

int delta_ax;  // Stores the change in acceleration

int ax_threshold = 1000; // The minimum acceleration value to trigger the button

void setup() {
  Serial.begin(9600); // Intialize I2C and the MPU connection
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
  }
}

void loop() {
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); // Read the current accelerometer data

  delta_ax = (old_ax - ax); // Calculate change in acceleration
  old_ax = ax; // Save the current acceleration reading to the old acceleration reading variable
  
  Serial.print("delta_ax = ");  // Print the change in acceleration in the serial monitor - this is super useful for debugging
  Serial.println(abs(delta_ax));

  if (abs(delta_ax) > ax_threshold) // Check if change in acceleration is higher than the threshold - use "delta_ax" for positive direction, "-(delta_ax)" for opposite direction, or "abs(delta_ax)" for the absolute acceleration to ignore direction
  {
    Keyboard.press('a'); // If true, press the "a" key
    delay(100); // Length of time the button is held down
    Keyboard.release('a');
    delay(500);  // Delay if needed to avoid spamming the button
  }
}
