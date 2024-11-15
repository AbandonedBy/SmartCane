#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <iostream>

// Ultrasonic Sensor Pins
const int trigPin = 9;
const int echoPin = 10;

// Buzzer and LED Pins
const int buzzer = 11;
const int ledPin = 13;

// Wi-Fi and ThingSpeak Settings
const char* ssid = "Your_SSID";                 // Replace with your Wi-Fi SSID
const char* password = "Your_PASSWORD";          // Replace with your Wi-Fi Password
const char* api_key = "YOUR_THINGSPEAK_API_KEY"; // Replace with your ThingSpeak API Key
const char* server = "api.thingspeak.com";

long duration;
int distance;
int safetyDistance = 50;  // Set safety distance to 50 cm

void setup() {
  // Initialize sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Serial monitor setup
  Serial.begin(9600);
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    std::cout << "Connecting to Wi-Fi..." << std::endl;
  }
  std::cout << "Connected to Wi-Fi" << std::endl;
}

int measureDistance() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

void triggerAlert() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
  delay(100);
}

void noAlert() {
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzer, LOW);
}

void sendDataToThingSpeak(int distanceValue) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    std::string url = "http://" + std::string(server) + "/update?api_key=" + std::string(api_key) + "&field1=" + std::to_string(distanceValue);
    http.begin(url.c_str());
    int httpResponseCode = http.GET();
    
    std::cout << "HTTP Response code: " << httpResponseCode << std::endl;
    http.end();
  } else {
    std::cout << "Wi-Fi disconnected, attempting to reconnect..." << std::endl;
    WiFi.begin(ssid, password);
  }
}

void loop() {
  // Object Detection
  distance = measureDistance();
  std::cout << "Distance: " << distance << " cm" << std::endl;

  if (distance < safetyDistance) {
    triggerAlert();
  } else {
    noAlert();
  }

  // Send Data to ThingSpeak every 15 seconds
  if (millis() % 15000 < 50) {
    sendDataToThingSpeak(distance);
  }
  
  delay(200); // Delay between readings
}

int main() {
  setup();
  while (true) {
    loop();
  }
  return 0;
}
