#include <Arduino.h>
#include <EspMQTTClient.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include "credentials.h"
#include "controllMqttInputs.h"
#include <Servo.h> // servo library  

Servo servo;

#define POWERPIN D1
#define DIRPIN1 D2
#define DIRPIN2 D3
const char* ssid = WifiSSID;
const char* password = WiFiPassword;
bool upKeyDown= false;
bool goingForward=false;
bool goingBackwards=false;

EspMQTTClient client(
  ssid,           // WifiSSID
  password,       // WifiPassword
  "maqiatto.com", // MQTT broker ip
  MqttUsername,   // MQTT username
  MqttPassword,   // MQTT password
  "ordinador",    // Unique client name 
  1883            // port 
);

void initializeServo() {
servo.attach(0);
}
void driveRight(){
  servo.write(160);
}
void driveLeft(){
  servo.write(20);

}

void driveForward(){
  digitalWrite(DIRPIN1, LOW);
  digitalWrite(DIRPIN2, HIGH);
  analogWrite(POWERPIN, 256);
  Serial.print("going forward");
}
void stopDriving()
{
  //digitalWrite(motorPin, LOW);
  analogWrite(POWERPIN, 0);
  Serial.println("stopped");
}
void driveBackwards(){
  digitalWrite(DIRPIN1, HIGH);
  digitalWrite(DIRPIN2, LOW);
  analogWrite(POWERPIN, 256);
  Serial.print("going backwards");
}

void handleMotorControll(const String &payload) {
  // Check if the payload is "up"
  if (payload   == "up") {
    driveForward(); 
    goingForward=true;
    goingBackwards=false;
  }
  else if (payload == "down"){
    driveBackwards();//drive backwards
    Serial.print("going back");
    goingBackwards=true;
    goingForward=false;
  }
  else if(payload =="left")
  {
    driveLeft();
    Serial.print("going left");
  }
  else if(payload =="right")
  {
    driveRight();
    Serial.print("going right");
  }
  else {
    // Stop the motor or handle other payloads if necessary
    stopDriving();
    servo.write(90);
  }
}

void setUpWiFi()
{
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print("Connecting to ");
    Serial.println(ssid);
  }
}

void onConnectionEstablished()
{
  client.subscribe(MqttTopic, [](const String &topic, const String &payload) {
    Serial.println("Received message:");
    Serial.print("Topic: ");
    Serial.println(topic);
    Serial.print("Payload: ");
    Serial.println(payload);
    handleMotorControll(payload);//call handleMotorControll with the given payload e.g "up" 
  }); 
}