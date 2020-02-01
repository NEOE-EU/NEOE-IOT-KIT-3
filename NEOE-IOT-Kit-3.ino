/***************************************************************************
  This is a library for the DHT22 temerature and humidity sensor.
  Developed for the NEOE-IOT-Kit 3 "Temperature and humidity with 
  DHT22 / AM2302"
  www.neoe.io/...
  
  Developed with input and suggestions from the community. 
  Please share your feedback, thougths and suggestions with us.
  www.neoe.io/kontakt/

  Date of last change: February 1st, 2020
 **************************************************************************/
 
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <DHT.h>

/* BLYNK Connection Settings */
char auth[] = "ADD YOUR BLYNK-TOKEN HERE";
char ssid[] = "ADD THE SSID OF YOUR WLAN HERE";
char pass[] = "ADD THE PASSWORD OF YOUR WLAN HERE";

#define DHTPIN 5        // Digital sensor is connected, e.g. D1 = PIN 5
#define DHTTYPE DHT22   // Type of DHT-Sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  Blynk.begin(auth, ssid, pass);
  dht.begin();

}

void loop() {

  /* Ensure that Blynk reconnects in case of lost connection */
  if(!Blynk.connected() ) {
    Blynk.connect();
  }

  Blynk.run(); // Initiates Blynk

  /* Read data from Sensor */
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  /* Send data to Blynk */
    Blynk.virtualWrite(V0, t);    // Temperature
    Blynk.virtualWrite(V1, h);    // Humidity
  
  delay(1000);

}
