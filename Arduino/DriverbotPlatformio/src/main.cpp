#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "controllMqttInputs.h"
#include "credentials.h"
#include <Servo.h> 

//define the different pins on ESP
#define POWERPIN D1
#define DIRPIN1 D2
#define DIRPIN2 D3
#define ECHOPIN D5
#define TRIGPIN D6

#define MetricSystem

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  setUpWiFi();//connect to WiFi
   
//pin defining
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(DIRPIN1, OUTPUT);
  pinMode(DIRPIN2, OUTPUT);
  pinMode(POWERPIN, OUTPUT);

  // Connection successful
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  initializeServo();
  servo.write(90);// move servo back to the middle when running scirpt so car goes straight
}

void loop() {
  client.loop(); // Maintain MQTT connection
    if (!client.isConnected()) {
    onConnectionEstablished();
 
  }
    distanceMeater();
}
