#include "ssd1306.h"
#include "font.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    SSD1306 device(0x3c, SSD1306_128_64);
    Font *currentFont = &font1;
    PixelCoordonate x = 0, y = 0;
    DisplayColor color = DisplayWhiteColor, backgroundColor = DisplayBlackColor;
    int vsize = 1, hsize = 1;
    if (device.openDevice("/dev/i2c-2") != 0) {
        printf("Problem to open device\n");
        return 1;
    }
    if (device.initDevice() != 0) {
        printf("Problem to init device\n");
        return 1;
    }

    device.getDisplay()->clearDisplay();
    device.getDisplay()->setOrientation(DisplayUpSideDownOrientation);
//    device.getDisplay()->drawLine(0,0,50,50 ,DisplayWhiteColor);
    device.getDisplay()->printString(x, y,"Hola 1 2 3 4 5 6 7 8" , color, backgroundColor, currentFont, 1, 1);
    device.getDisplay()->printString(x,y, "HOLA", color,backgroundColor,currentFont, 2,2);
    device.pushDisplay();
    return 0;
}
