#include <EspMQTTClient.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "ABBgym_2.4";
const char* password = "mittwifiarsabra";

unsigned long lastPublishTime = 0;
const unsigned long publishInterval = 5000; // 5000 milliseconds (5 seconds)


EspMQTTClient client(
  ssid,           // WifiSSID
  password,                        // WifiPassword
  "maqiatto.com",             // MQTT broker ip
  "gustav.strom@hitachigymnasiet.se",   // MQTT username
  "hejhejhej",                          // MQTT password
  "ordinador",     // Unique client name 
  1883                                // port 
);

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
  client.subscribe("gustav.strom@hitachigymnasiet.se/test", [](const String &topic, const String &payload) {
    Serial.println("Received message:");
    Serial.print("Topic: ");
    Serial.println(topic);
    Serial.print("Payload: ");
    Serial.println(payload);
  });
  
}

void publishToBroker()
{if (millis() - lastPublishTime >= publishInterval) {
    // Check if it's time to publish a message
    client.publish("gustav.strom@hitachigymnasiet.se/test", "esp message");
    lastPublishTime = millis(); // Update the last publish time
    delay(1000); // Add a delay of 1000 milliseconds (1 second)
  }}

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  setUpWiFi();
  onConnectionEstablished();  


  // Connection successful
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());


}

void loop() {
  client.loop(); // Maintain MQTT connection
  publishToBroker();
}
