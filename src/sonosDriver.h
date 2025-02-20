#ifndef SONOSDRIVER_H
#define SONOSDRIVER_H

#include <vector>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>



using std::vector;
enum class PlaybackState { PAUSED_PLAYBACK, PLAYING, UNCLEAR };


class sonosDriver{
    private: 
    const String serverName = "http://192.168.0.132:5005/zones";

    vector<String> roomList = {"Sonos", "Küche", "Sonos Roam"};

    const char* ssid = "((((wifi))))";
    const char* password = "M2u0s1j7a";
    PlaybackState state; 

    HTTPClient http;


    public:
    sonosDriver();
    String getPlaybackState();


};


#endif