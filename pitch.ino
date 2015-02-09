// Controlling the cannon's pitch

#include <PubSubClient.h>
#include <stepper.h>

void setup() {
  // Initialize motor output pins

  // Initialize serial communications
  Serial.begin(9600);
  Serial.println("IoT Marshmallow Cannon");
  Serial.println("   Pitch controller   ");

  // Initialize MQTT Client

}

void loop() {
  // Continuously listen for relevant MQTT message

  // When message is received, parse for command

  // If command is valid, raise barrel to requested pitch

  // When complete, send MQTT message indicating success

}
