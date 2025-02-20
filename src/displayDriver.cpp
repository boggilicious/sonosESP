#include "displayDriver.h"

displayDriver::displayDriver() : displayContr(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET) {
    // Attempt to initialize the display
    if (!displayContr.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
        while (true); // Stop execution if display fails
    }

    displayContr.clearDisplay();
    displayContr.fillScreen(BLACK);
    displayContr.display();
    Serial.println("Display initialized");
}

void displayDriver::displayRoom(const String &name) {
    int16_t x, y; 
    uint16_t w, h;
    displayContr.getTextBounds(name, 0,0,&x,&y,&w,&h);

    x = (SCREEN_WIDTH - w) / 2; 

    displayContr.fillRect(0,0,SCREEN_WIDTH, 10, BLACK);
    displayContr.setCursor(x, 0);
    displayContr.setTextSize(1);
    displayContr.setTextColor(WHITE);
    displayContr.print(name);
    displayContr.display();  
}

void displayDriver::displayPlaybackState(const String &state){
    if(!strcmp(state.c_str(), "Playing")){
        displayContr.fillRect(0,10,53,SCREEN_WIDTH, BLACK); 
        displayContr.drawBitmap(0,10,displayDriver::playback_bitmaps[0],25,25,WHITE,BLACK); 
        displayContr.display();
    }
    else{
        displayContr.fillRect(0,10,53,SCREEN_WIDTH, BLACK); 
        displayContr.drawBitmap(0,10,displayDriver::playback_bitmaps[1],25,25,WHITE,BLACK); 
        displayContr.display();
    }
}

void displayDriver::displayIP(const String &ip){
    int16_t x, y; 
    uint16_t w, h;
    displayContr.getTextBounds(ip, 0,0,&x,&y,&w,&h);

    x = (SCREEN_WIDTH - w) / 2; 

    displayContr.fillRect(0,54, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);

    displayContr.setCursor(x, 54);
    displayContr.setTextSize(1);
    displayContr.setTextColor(WHITE);
    displayContr.print(ip);
    displayContr.display();  
}
