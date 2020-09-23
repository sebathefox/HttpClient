/**
 * This is the main entry file for the application.
 * @file main.cpp
 * @author Sebastian Davaris
 * @date 16-09-2020
 */

#if !FEATURE_LWIP
    #error [NOT_SUPPORTED] LWIP not supported for this target
#endif

// Includes the main mbed file
#include "mbed.h"

// Filesystem includes
#include "FATFileSystem.h"
#include "SDBlockDeviceDISCOF746NG.h"

// Sensor includes
#include "DHT.h"

// Display includes
#include "TS_DISCO_F746NG.h"
#include "LCD_DISCO_F746NG.h"

// C++ STD includes
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

// Custom classes
#include "KeyboardNumeric.h"
#include "Button.h"
#include "HttpClient.h"

/************************
*       IMPORTANT!!!    *
*************************/
#define DEVICE_TOKEN "aeada52e-ad7c-4306-9fe8-53812684d6a4"

TS_DISCO_F746NG ts;
LCD_DISCO_F746NG lcd;

// Instantiate the Block Device for sd card on DISCO-F746NG
SDBlockDeviceDISCOF746NG bd;
FATFileSystem fs ("fs");

// Forward declarations.

/**
 * Draws a >BMP< image to the screen.
 * @author Sebastian Davaris
 * @date 16-09-2020
 * @param name The name of the file.
 * @param x The x coordinate to begin drawing the image.
 * @param y The y coordinate to begin drawing the image.
 */
void drawImage(char * name, uint16_t x, uint16_t y);

DHT tempHumidSensor(D4, DHT22);


void onOnePressed(Button* sender) {
    printf(sender->getLabel().c_str());
}


/**
 * The main entrypoint for the application.
 * 
 */
int main()
{   

//    std::vector<Button> buttons;
//
//    int size = 48;
//    int row = 0;
//    int col = 0;
//
//    for(int i = 0; i < 9; i++) {
//        if(i % 3 == 0 && i != 0) {
//            row++;
//            col = 0;
//        }
//
//        buttons.push_back(Button(0 + (col * size), 0 + (row * size), size, size, &ts, &lcd));
//        buttons[i].setLabel(static_cast<ostringstream*>( &(ostringstream() << (i + 1)) )->str());
//
//        col++;
//    }
//    buttons.push_back(Button(0 + (1 * size), 0 + (3 * size), size, size, &ts, &lcd));
//    buttons[9].setLabel("0");
//
//
//    for(int i = 0; i < 10; i++) {
//        buttons[i].draw();
//    }

    // Base variables.
    
    TS_StateTypeDef TS_State;
    
    // Initializes the touch display.
    ts.Init(420, 272);

    // Mounts the SD card
    fs.mount(&bd);

    // Initializes the HTTP client.
    HttpClient http("192.168.1.1", 8000);

    //drawImage("/fs/images.bmp", 0, 0);

    std::string oldValue = "";

    KeyboardNumeric numericKeyboard(0, 0, &lcd, &ts);

    numericKeyboard.getButton(1).attach(onOnePressed);

    while(1) {
        /*ts.GetState(&TS_State);
        if(TS_State.touchDetected) {*/

        numericKeyboard.poll();

        numericKeyboard.draw();

//        tempHumidSensor.readData();
//
//        float celcius = tempHumidSensor.ReadTemperature(CELCIUS);
//
//        if(oldValue == static_cast<ostringstream*>( &(ostringstream() << celcius) )->str()) {
//            wait(0.2);
//            continue;
//        }
//
//        lcd.DisplayStringAt(0, LINE(3), (uint8_t*) static_cast<ostringstream*>( &(ostringstream() << celcius) )->str().c_str(), CENTER_MODE);
//
//        http.addBodyParameter("value", static_cast<ostringstream*>( &(ostringstream() << celcius) )->str());
//        http.addBodyParameter("&category", "1");
//        http.addBodyParameter("&token", DEVICE_TOKEN);
//
//        http.send("/api/v1/data");
//
//        lcd.DisplayStringAt(0, LINE(1), (uint8_t *)"SUCCESS!!!", CENTER_MODE);
//
//        oldValue = static_cast<ostringstream*>( &(ostringstream() << celcius) )->str();
//
//
//        wait(0.2);
    }

}

/**
 * Draws a >BMP< image to the screen.
 * @author Sebastian Davaris
 * @date 16-09-2020
 * @param name The name of the file.
 * @param x The x coordinate to begin drawing the image.
 * @param y The y coordinate to begin drawing the image.
 */
void drawImage(char * name, uint16_t x, uint16_t y){
    int fileSize;
    char * buffer;
    
    //printf("WORKING1");
    
    FILE *Image = fopen(name, "rb");  // open the bmp file
  
  //printf("WORKING2");
  
    //obtain file size:
    fseek (Image , 0 , SEEK_END);
    fileSize = ftell (Image);
    rewind (Image);
    
    //printf("WORKING3");
    
    // allocate memory to contain the whole file:
    buffer = (char*) malloc (sizeof(char)*fileSize);
    
    //printf("WORKING4");
    
    // copy the file into the buffer:
    fseek (Image, 0 , SEEK_SET );
    // set SD file data start position    
    fread (buffer,1,fileSize,Image);
    fclose (Image);

    //printf("WORKING5");

    //Draw image
    lcd.DrawBitmap(x,y,(uint8_t *)buffer);

 /* Get bitmap data address offset */

    //printf("WORKING6");

    //Free allocated memory
    free (buffer);
}