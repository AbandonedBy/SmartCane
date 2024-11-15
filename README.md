Smart Cane Project
Overview
The Smart Cane project is a wearable device designed to assist visually impaired individuals by providing real-time proximity alerts through an ultrasonic sensor. The system uses an ESP8266 microcontroller, an ultrasonic distance sensor (HC-SR04), and an alert system comprising a buzzer and an LED. The project aims to offer enhanced safety by notifying the user of nearby obstacles, helping them navigate their surroundings more confidently.

Key Features:
Distance Measurement: Using an ultrasonic sensor, the system measures the distance to an object in front of the user.
Proximity Alerts: The system triggers a buzzer and LED light when an object comes within a predefined safety distance (50 cm in this case).
Wi-Fi Connectivity: The ESP8266 connects to a Wi-Fi network, enabling real-time monitoring and sending distance data to cloud platforms like ThingSpeak for analysis or remote viewing.
Simple and Compact: The entire system is compact and portable, suitable for integration into a cane or other wearable devices.
Hardware Components
ESP8266 (NodeMCU or Similar):

A low-cost, Wi-Fi enabled microcontroller that acts as the brain of the project. It reads sensor data, controls the alert system, and connects to Wi-Fi to send data.
HC-SR04 Ultrasonic Sensor:

A sensor that measures the distance between the device and any object in front of it by emitting and receiving ultrasonic sound waves.
Buzzer:

Emits a sound when an object comes within the predefined safety distance (50 cm).
LED:

Provides a visual cue for proximity alerts, lighting up when the user is approaching an obstacle.
Resistors (for the LED):

A 220Ω resistor to limit current to the LED, ensuring it operates within safe voltage levels.
Wires and Breadboard (optional for prototyping):

Used for connecting components in a stable configuration during testing and development.
Software Requirements
Arduino IDE:

The primary environment used for programming the ESP8266. Install the ESP8266 board package from the board manager for compatibility.
Libraries:

ESP8266WiFi: To handle Wi-Fi connectivity.
ESP8266HTTPClient: For sending HTTP requests to cloud platforms like ThingSpeak.
ThingSpeak Account (optional for data logging):

An account on ThingSpeak for sending and visualizing the distance data collected by the ultrasonic sensor.
How It Works
Wi-Fi Connection:
On startup, the system connects to a Wi-Fi network using credentials provided in the code.
Distance Measurement:
The ultrasonic sensor continuously measures the distance to the nearest object.
Alert System:
If the measured distance is below the set threshold (50 cm), the buzzer is triggered, and the LED lights up, notifying the user of an obstacle in their path.
Data Logging:
Every 15 seconds, the measured distance is sent to ThingSpeak using an HTTP request, where the data can be monitored remotely via a web dashboard.
Circuit Diagram
For wiring the components to the ESP8266, refer to the circuit diagram below:

HC-SR04 Ultrasonic Sensor:

VCC to 3.3V
GND to GND
Trig to GPIO 9 (D3)
Echo to GPIO 10 (D6)
Buzzer:

Positive terminal to GPIO 11 (D7)
Negative terminal to GND
LED:

Anode (long leg) to GPIO 13 (D5)
Cathode (short leg) to GND with a 220Ω resistor.
Installation
Install the Arduino IDE: Download and install the Arduino IDE.
Add ESP8266 Board: In the Arduino IDE, go to File > Preferences and add the ESP8266 board URL in the "Additional Boards Manager URLs" section.
Select ESP8266 Board: Go to Tools > Board > NodeMCU 1.0 (ESP-12E Module) or similar.
Install Libraries: Go to Sketch > Include Library > Manage Libraries, and install the ESP8266WiFi and ESP8266HTTPClient libraries.
Upload the Code: Connect the ESP8266 to your computer using a USB cable, and upload the code to the board.
Usage
Power the System: Connect the ESP8266 to a power source (USB or battery).
Configure Wi-Fi Settings: Update the SSID and password in the code to match your Wi-Fi credentials.
Run the System: Once the system is powered on, the ultrasonic sensor will begin measuring distances, triggering alerts when the user is within 50 cm of an object. The data will be logged to ThingSpeak for monitoring.
Future Improvements
Adaptive Sensitivity: Implement adaptive thresholding to adjust the safety distance based on user preference.
Battery Optimization: Incorporate low-power sleep modes for extended battery life.
Mobile App Integration: Develop a mobile app to monitor the device and adjust settings remotely.
Obstacle Detection in Multiple Directions: Add more sensors to detect obstacles in different directions for 360-degree awareness.
License
