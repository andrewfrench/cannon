// Controlling the cannon's pitch

#include <WiFi.h>
#include <PubSubClient.h>
#include <stepper.h>

// Define I/O pins
#define MOTOR_OUTPUT  0

void setup() {
  // Initialize motor output pins

  // Initialize serial communications
  Serial.begin(9600);
  Serial.println("IoT Marshmallow Cannon");
  Serial.println("   Pitch controller   ");

  // Initialize WiFi connection

  // Initialize MQTT Client

}

void loop() {
  // Continuously listen for relevant MQTT message

  // When message is received, parse for command

  // If command is valid, raise barrel to requested pitch

  // When complete, send MQTT message indicating success

}
