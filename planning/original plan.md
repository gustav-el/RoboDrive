# Plan
This is the offical plan of my driverbot 

# What is this?
**short description**

This project is called Driverbot, it is meant to be a driving car made by a mix of both lego and 3d printed parts. The project consists of a website to controll an Esp8266 
thorugh an MQTT broker which 
controlls a dc motor and a servo. The dc motor is responsible for the car being able to drive forward/backward meanwhile the servo makes sure the car can turn.

# How will it work?

* You connect to the MQTT broker
* Send packages from the website
* The Esp receives the packages and adjust the speed and turns on/off the motor accordingly

  ![canvas_driberbot-240418_0802](https://github.com/abbindustrigymnasium/driverbot-strom-el/assets/144807857/c4fe4e16-3f7e-4467-88f4-d6a42b00dc1b)


# Goals 
My goal with this project is to make a fully functional driving car with some additional features. **(hopefully high grade)**

**1. PARS** proximity alert and reaction system.

Using a distance sensor the Esp will read the distance to the nearest object(in the front) and stop or slow down the motor therefore causing the car to decrease its speed 
towards the object ahead thus the car does not collide with other objects.

**2. Autodrive**

If a button on the website is pressed the car will continue driving aslong as it does not get to close to an object(not in the website skiss)


# Order of work
**1. Set up MQTT** Make it so that the MQTT is intergrated to the website so that you can give inputs on the website and it can print/or flash the Esp **Estimated finish** week 17

**2. set up the website** Set up the website so that it can communicate with the Esp through inputs on the website **Estimated finish**  week 18

**3. finish the car** Finish the car so that it can be fuly remotely controlled by the users inputs.**Estimated finish** week 20

**4. Intergrate PARS** intergrate PARS to the driverbot so that it does not collide. **Esitimated finsh** week 21

**5. Drive** Drive the car



# mini skiss of the websites 2 pages
![bild](https://github.com/abbindustrigymnasium/driverbot-strom-el/assets/144807857/fc18ded2-e41f-4392-b54a-831a9c3f0108)


                                                                                                                                
