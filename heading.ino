// Controlling the cannon's heading

#include <PubSubClient.h>
#include <stepper.h>

void setup() {
  // Initialize motor output pins

  // Initialize serial communications
  Serial.begin(9600);
  Serial.println("IoT Marshmallow Cannon");
  Serial.println("  Heading controller  ");

  // Initialize MQTT Client

}

void loop() {
  // Continuously listen for relevant MQTT message

  // When message is received, parse for command

  // If command is valid, turn to requested heading

  // When complete, send MQTT message indicating success
  
}
