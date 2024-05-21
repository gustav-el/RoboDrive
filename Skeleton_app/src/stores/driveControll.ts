//this file controlles the connection to the MQTT broker aswell as publishing and subscribing to it
  import mqtt from 'mqtt';
  import {MQTT_USERNAME, MQTT_PASSWORD, MQTT_TOPIC} from '../components/credentials';
  //mqtt broker details
  message: String
  const brokerURL='ws://maqiatto.com:8883';
  
  const topic=MQTT_TOPIC
  //client options
  const options: mqtt.IClientOptions={
      clientId:'client_website',
      username: MQTT_USERNAME,
      password: MQTT_PASSWORD,
      clean: false,
  };
  //logging the message from the broker and connecting
  const client=mqtt.connect(brokerURL, options)
  const onMessage = (topic: any, message: string) => {
  console.log(message);
  const time = new Date().getTime();
};
//exports function which handles the messages from buttons to the car see more in Driverapge
 export function onSend(brokerURL: string, message: string) {
    //console.log(message);
    client.publish(topic, message, (err) => {
      if (err) {
         console.log('Message failed to publish');
      }
 });
    onMessage(brokerURL, message);
  }

  //connect to the broker and subscribe to it
  client.on('connect', () => {
     console.log('Connected to MQTT broker');
    client.subscribe(topic, (err) => {
      if (!err) {
          console.log('Subscribed to:', topic);
      }
    });
  });
  
  //logs the messages and on which topic
  client.on('message', (topic, message) => {
    console.log(`Received message on topic ${topic}: ${message.toString()}`);
  });  