#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#define OLED_RESET 7
Adafruit_SSD1306 display(OLED_RESET);

void setup()
{
display.print("0");
display.display();
}
void loop()
{

}
