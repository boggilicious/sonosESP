#ifndef DISPLAYDRIVER_H
#define DISPLAYDRIVER_H

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1 
#define SCREEN_ADDRESS 0x3C

class displayDriver {
private:
Adafruit_SSD1306 displayContr;
// 'Unbenanntes_Projekt 2', 25x25px
const unsigned char play_bit [8125] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
	0x07, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 
	0x07, 0xff, 0x80, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x0f, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xf0, 0x00, 
	0x0f, 0xff, 0xe0, 0x00, 0x07, 0xff, 0xc0, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 
	0x0f, 0xf8, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 
	0x0f, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00
};
// 'Unbenanntes_Projekt 3', 25x25px
const unsigned char pause_bit [8125] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0xa0, 0x00, 
	0x0f, 0x01, 0xe0, 0x00, 0x0f, 0x01, 0xe0, 0x00, 0x0f, 0x81, 0xf0, 0x00, 0x0f, 0x01, 0xe0, 0x00, 
	0x0f, 0x01, 0xe0, 0x00, 0x0b, 0x01, 0x60, 0x00, 0x0b, 0x01, 0x60, 0x00, 0x0f, 0x01, 0xe0, 0x00, 
	0x0f, 0x01, 0xe0, 0x00, 0x0f, 0x81, 0xf0, 0x00, 0x0f, 0x81, 0xf0, 0x00, 0x0f, 0x01, 0xe0, 0x00, 
	0x0f, 0x81, 0xf0, 0x00, 0x0f, 0x01, 0xe0, 0x00, 0x0f, 0x81, 0xf0, 0x00, 0x0f, 0x81, 0xf0, 0x00, 
	0x0f, 0x81, 0xf0, 0x00, 0x0f, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 256)
const int epd_bitmap_allArray_LEN = 2;
const unsigned char* playback_bitmaps[2] = {
	play_bit,
	pause_bit
};

public:
    displayDriver();  
    void displayRoom(const String &name);

    void displayPlaybackState(const String &state);

    void displayIP(const String &ip);
};

#endif