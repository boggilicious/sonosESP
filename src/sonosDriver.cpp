#include "sonosDriver.h"

sonosDriver::sonosDriver() : roomList{}{
    WiFi.begin(ssid, password);

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(100);
    }

}


String sonosDriver::getPlaybackState() {
    const char* url = "http://192.168.0.132:5005/Sonos/state";  
    http.begin(url);

    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
        String payload = http.getString();

        DynamicJsonDocument doc(1024);  // Adjust buffer size based on JSON response
        if (deserializeJson(doc, payload)) {
            http.end();
            return "Error";
        }

        // Extract "playbackState" field
        if (doc["playbackState"].is<String>()) {
            String token = doc["playbackState"].as<String>();
            http.end();

            if(!token.compareTo("PAUSED_PLAYBACK")){
                state = PlaybackState::PAUSED_PLAYBACK;
                return "Paused";
            } else if(!token.compareTo("PLAYING")){
                state = PlaybackState::PLAYING;
                return "Playing";
            }
            state = PlaybackState::UNCLEAR;
                return "Unclear";

        } else {
            http.end();
            return "Not Found";
        }
    } else {
        http.end();
        return "HTTP Error";
    }
}
