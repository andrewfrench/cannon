// Controlling the cannon's heading

#include <WiFi.h>
#include <PubSubClient.h>
#include <stepper.h>

// Define I/O pins, user/token strings, and other constants
#define MOTOR_OUTPUT        0
#define WIFI_CONN_MAX_TRIES 10
#define MQTT_CONN_MAX_TRIES 10
#define THINGFABRIC_USER    "62a2c37b-5729-41d0-b4ac-68ea0761bf6a"
#define THINGFABRIC_TOKEN   "cf68c61d43b1c24d100c995ef5b0a373"

// Store WiFi credentials
char * ssid = "2lemetry";
char * pass = "connecteverydevice";
char * device_id = "cannon-heading";

// Create client handles in global scope
WiFiClient wifi_client;
PubSubClient client("q.thingfabric.com", 1883, message_arrived, wifi_client);

// Function prototypes
void wifi_connect();
void mqtt_connect();
void message_arrived(char*, byte*, unsigned int);

void setup() {
  // Initialize motor output pins

  // Initialize serial communications
  Serial.begin(115200);
  delay(1000);
  Serial.println("IoT Marshmallow Cannon");
  Serial.println("  Heading controller  ");

  // Initialize WiFi connection
  wifi_connect();

  // Initialize MQTT Client
  mqtt_connect();

}

void loop() {
  // Continuously listen for relevant MQTT message

  // When message is received, parse for command

  // If command is valid, turn to requested heading

  // When complete, send MQTT message indicating success

}

void wifi_connect() {
  int wifi_status = WL_IDLE_STATUS;
  int wifi_conn_tries = 0;

  while(wifi_status != WL_CONNECTED && wifi_conn_tries < WIFI_CONN_MAX_TRIES) {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);

    wifi_status = WiFi.begin(ssid, pass);

    // Delay 2s = 10000ms for network connection
    delay(2 * 1000);

    // Increment connection attempt counter
    wifi_conn_tries++;
  }

  if(wifi_conn_tries == WIFI_CONN_MAX_TRIES) {
    Serial.println("WiFi connection failed permanently!");
    Serial.println("(Max connection attempts reached)");

    // Hang out in here forever
    while(true);
  }

  // Confirm WiFi connection, print local IP
  Serial.println("Connection successful!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void mqtt_connect() {
  Serial.print("Attempting to establish MQTT connection as: ");
  Serial.println(device_id);

  int mqtt_conn_tries = 0;

  while(!client.connected() && mqtt_conn_tries < MQTT_CONN_MAX_TRIES) {
    if(!client.connect(device_id, THINGFABRIC_USER, THINGFABRIC_TOKEN)) {
      // MQTT connection succeeded
      Serial.println("MQTT connection successful!");

      client.publish("public/test/arduino", "hello, world!");

      break;
    } else {
      // MQTT connection failed
      Serial.println("MQTT connection failed.  Trying again...");
    }

    mqtt_conn_tries++;
  }

  if(mqtt_conn_tries == MQTT_CONN_MAX_TRIES) {
    Serial.println("MQTT connection failed permanently!");
    Serial.println("(Max connection attempts reached)");

    // Hang out in here forever
    while(true);
  }
}

void message_arrived(char * topic, byte * payload, unsigned int length) {
  // Parse this message and act accordingly
  Serial.println("Message arrived!");
  Serial.write(payload, length);
}
