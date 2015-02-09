// Controlling the cannon's trigger

#include <WiFi.h>
#include <PubSubClient.h>

// Define I/O pins
#define TRIGGER_PIN 0
#define SENSOR_PIN  0

void setup() {
  // Initialize trigger output pins

  // Initialize ready sensor input pins

  // Initialize serial communications
  Serial.begin(9600);
  Serial.println("IoT Marshmallow Cannon");
  Serial.println("  Trigger controller  ");

  // Initialize MQTT Client

}

void loop() {
  // Continuously listen for relevant MQTT message

  // When message is received, parse for command

  // If command is valid, fire cannon

  // When fired, send MQTT message indicating success

  // Reset trigger to allow pressure to build up
  // and for the cannon to fire again when ready
}
