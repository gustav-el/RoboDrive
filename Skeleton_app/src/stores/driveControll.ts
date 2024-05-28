//this file controlls the connection to the MQTT broker as well as publishing and subscribing to it
  import mqtt from 'mqtt';
  import {MQTT_USERNAME, MQTT_PASSWORD, MQTT_TOPIC} from '../components/credentials';
  //mqtt broker details
  
  const BROKER_URL='ws://maqiatto.com:8883';
  
  const TOPIC=MQTT_TOPIC
  //client options
  const OPTIONS: mqtt.IClientOptions={
      clientId:'client_website',
      username: MQTT_USERNAME,
      password: MQTT_PASSWORD,
      clean: false,
  };
  
  const client=mqtt.connect(BROKER_URL, OPTIONS)

  const onMessage = (TOPIC: string, message: string) => {
  console.log(message);
};
//export function which handles the messages from buttons to the car see more in Driverpage
 export function onSend(BROKER_URL: string, message: string) {
    client.publish(TOPIC, message, (err) => {
      if (err) {
         console.log('Message failed to publish');
      }
 });
    onMessage(BROKER_URL, message);
  }

  //connect to the broker and subscribe to the specified topic
  client.on('connect', () => {
     console.log('Connected to MQTT broker');
    client.subscribe(TOPIC, (err) => {
      if (!err) {
          console.log('Subscribed to:', TOPIC);
      }
    });
  });
  
  //logs the recieved message along with their topic
  client.on('message', (topic, message) => {
    console.log(`Received message on topic ${topic}: ${message.toString()}`);
  });  