# Plan
This is the offical plan of my driverbot 

# What is this?
**short description**

This project is called Driverbot, it is meant to be a driving car made by a mix of both lego and 3d printed parts. The project consists of a website to controll an Esp8266 
thorugh an MQTT broker which 
controlls a dc motor and a servo. The dc motor is responsible for the car being able to drive forward/backward meanwhile the servo makes sure the car can turn.

# Goals 
My goal with this project is to make a a fully functional driving car with some additional features.

**1. PARS** proximity alert and reaction system.

Using a distance sensor the Esp will read the distance to the nearest object(in the front) and stop or slow down the motor therefore causing the car to decrease its speed 
towards the object ahead thus the car doesnt collide with other objects.
