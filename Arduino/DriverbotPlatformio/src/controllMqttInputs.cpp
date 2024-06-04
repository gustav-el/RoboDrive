// File that controlls mqtt messages and handles them correctly and 

#include <Arduino.h>
#include <EspMQTTClient.h>//dependancy on PubSubClient
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include "credentials.h"
#include "controllMqttInputs.h"
#include <Servo.h> // servo library  
#define ECHOPIN D5
#define TRIGPIN D6

Servo servo;//create Servo object called servo


#define POWERPIN D1
#define DIRPIN1 D2
#define DIRPIN2 D3
//creates a constant pointer to the string imported from credentials.h
const char* ssid = WiFiSSID;
const char* password = WiFiPassword;

bool goingForward=false;
bool goingBackwards=false;

//create client object with given information
EspMQTTClient client(
  ssid,           
  password,       
  "maqiatto.com", 
  MqttUsername,   
  MqttPassword,   
  "ordinador",    
  1883   // TCP port
);

void initializeServo() {
servo.attach(2);//attach servo to correct pin
}
void driveRight(){
  servo.write(150);
}
void driveLeft(){
  servo.write(30);

}
void driveForward(){
  digitalWrite(DIRPIN1, LOW);
  digitalWrite(DIRPIN2, HIGH);
  analogWrite(POWERPIN, 256);
  Serial.print("going forward");
}
void stopDriving()
{
  analogWrite(POWERPIN, 0);
  Serial.println("stopped");
}
void driveBackwards(){
  digitalWrite(DIRPIN1, HIGH);
  digitalWrite(DIRPIN2, LOW);
  analogWrite(POWERPIN, 256);
  Serial.print("going backwards");
}

//
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
  else if(payload=="stop"){
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

// this function is called once connected to mqtt broker OBS if using EspMQTTClient this function must be implemented
void onConnectionEstablished()
{
  client.subscribe(MqttTopic, [](const String &topic, const String &payload) {
    //print out information about the recived messages
    Serial.println("Received message:");
    Serial.print("Topic: ");
    Serial.println(topic);
    Serial.print("Payload: ");
    Serial.println(payload);
    handleMotorControll(payload);//call handleMotorControll with the given payload e.g "up" 
  }); 
}
void distanceMeater(){
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2); // delay so distance sensor work
  digitalWrite(TRIGPIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  long duration = pulseIn(ECHOPIN, HIGH); // Measure pulse width of echo pin
float distance = duration * 0.034 / 2; // Convert pulse width to distance in cm

//if the distance is under 20cm stop driving 
    if(distance<=20){
    stopDriving();
    Serial.print("to close distance");
  }
}