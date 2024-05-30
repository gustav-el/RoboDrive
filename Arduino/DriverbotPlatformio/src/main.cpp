#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "controllMqttInputs.h"
#include "credentials.h"
#include <Servo.h> // servo library  
#define POWERPIN D1
#define DIRPIN1 D2
#define DIRPIN2 D3



void setup() {
  Serial.begin(115200);  // Initialize serial communication
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  setUpWiFi();
   //onConnectionEstablished(); 

  
  pinMode(DIRPIN1, OUTPUT);
  pinMode(DIRPIN2, OUTPUT);
  pinMode(POWERPIN, OUTPUT);

  // Connection successful
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  initializeServo();
  servo.write(90);
}

void loop() {
  client.loop(); // Maintain MQTT connection
    if (!client.isConnected()) {
    onConnectionEstablished();

  }
}
