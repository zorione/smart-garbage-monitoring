<h1>SMART DUSTBIN</h1>


In the present scenario, as the population is increasing day by day, the environment should be clean and hygienic. Overloaded garbage bins create unhygienic conditions for people as well as ugliness to that place leaving bad smell. To avoid all such situations, we are going to implement a project called IoT Based Smart Garbage Monitoring system.
This project introduces the design and implementation of garbage monitoring by measuring the garbage level in real time and to alert the municipality whenever the bin is full. The proposed system consists of ultrasonic sensors which measure the garbage level and a microcontroller which controls system operation. The system shows the status of garbage bin levels in a website from the sensor data and also sends a notification to mobile whenever a bin is full, so that the waste can be collected. 

<h2>Components Used:</h2>

1.	Arduino UNO

2.	Ultrasonic Sensor HC-SR04

3.	ESP8266 (ESP-01) Wi-Fi Module

4.	Breadboard

5.	Jumper Wires

6.	Dustbins






<h2>Working:</h2>


The Smart Bin uses ultrasonic sensors to monitor the height of garbage in any dustbin. Ultrasonic sensors are placed on the interior side of the lid of each dustbin.
The circuitry inbuilt on the module calculates the time taken for the ultrasonic wave to come back. Now, the speed of sound in air is known. 

Using the simple formula Distance = Speed * Time, the amount of garbage in the dustbin is calculated.
As trash increases, the distance between the sensor and the dustbin decreases. This live data is sent to the microcontroller. The microcontroller then processes the data and using the ESP8266 WiFi module, it sends the data to the server. Once the amount of garbage in each dustbin is available to the server, the dustbin that requires attention is determined by considering the level of garbage.


>_The system shows the status of garbage bin levels to the user on a website from the sensor data and also sends a notification to mobile whenever a bin is full, so that the waste can be collected. This bin data is also saved to a database for further analysis._

_Web Application will be uploaded soon._




























