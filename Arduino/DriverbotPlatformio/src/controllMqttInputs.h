#ifndef ESTABLISHBROKERCONNECTION_H
#define ESTABLISHBROKERCONNECTION_H

#include <EspMQTTClient.h>

extern EspMQTTClient client;
void setUpWiFi();
void onConnectionEstablished();
void stopDriving();

extern bool upKeyDown;
#endif // ESTABLISHBROKERCONNECTION_H
