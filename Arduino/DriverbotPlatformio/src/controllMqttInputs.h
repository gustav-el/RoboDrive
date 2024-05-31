#ifndef ESTABLISHBROKERCONNECTION_H
#define ESTABLISHBROKERCONNECTION_H
#include <Servo.h>
#include <EspMQTTClient.h>

extern Servo servo; // Declare the servo object
extern EspMQTTClient client;
void setUpWiFi();
void onConnectionEstablished();
void stopDriving();
void initializeServo();
void distanceMeater();

extern bool upKeyDown;
#endif // ESTABLISHBROKERCONNECTION_H
