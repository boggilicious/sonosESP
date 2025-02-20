
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <random>
#include <WiFi.h>
#include <HTTPClient.h>
#include "displayDriver.h"
#include "sonosDriver.h"

int playPause_btn = 0;


String serverName = "http://192.168.0.40:5005/Sonos/pause";

String sonosDevice = "Sonos";
displayDriver * displayContr; // Create an instance of the class
sonosDriver * sonosAPI;

void setup(){
  Serial.begin(115200);
  Serial.print("init serial");
  displayContr = new displayDriver();

  displayContr->displayRoom("sonos ESP32");

  sonosAPI = new sonosDriver();

}
void loop() {
    displayContr->displayRoom(sonosAPI->getPlaybackState());
    displayContr->displayPlaybackState(sonosAPI->getPlaybackState());
    displayContr->displayIP(WiFi.localIP().toString());
    delay(1000);
}

