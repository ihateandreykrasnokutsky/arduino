#include <Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

Adafruit_SSD1306 display(7);
int val;

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop()
{
    val=analogRead(14);
    display.setCursor(0,0);
    //display.print(val);
    //display.display();
    delay(1000);
    display.clearDisplay();
    display.display();
}
