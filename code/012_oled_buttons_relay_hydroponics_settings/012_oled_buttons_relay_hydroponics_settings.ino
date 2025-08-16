#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LowPower.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Set the LCD address to 0x27 for a 16 chars and 2 line display
#define BUTTON_PIN_2 2
#define BUTTON_PIN_3 3
#define BUTTON_PIN_4 4
#define BUTTON_PIN_5 5
#define RELAY_PIN_6 6
#define RELAY_PIN_7 7
#define RELAY_PIN_8 8
#define RELAY_PIN_9 9

unsigned long startTime = millis();
uint8_t i_display=0; //uint8_t to optimize memory, because it's 1 byte, and int is 2 bytes
const char* screen_mode[]={"t","t+b","off"};
const char* pump_mode[]={"1/10","1/20","1/40","1/80","on","off"};
uint8_t i_pump=0;
unsigned long pump_work_time=5000;
//unsigned long pump_rest_time[]={720*60000,480*60000,240*60000,120*60000};
unsigned long pump_cycle_time[]={10000,20000,40000,80000};
unsigned long pump_start_time=millis();
unsigned long elapsed=0;

void setup() {
  digitalWrite(RELAY_PIN_6, HIGH);
  digitalWrite(RELAY_PIN_7, HIGH);
  digitalWrite(RELAY_PIN_8, HIGH);
  digitalWrite(RELAY_PIN_9, HIGH);
  pinMode(RELAY_PIN_6, OUTPUT);
  pinMode(RELAY_PIN_7, OUTPUT);
  pinMode(RELAY_PIN_8, OUTPUT);
  pinMode(RELAY_PIN_9, OUTPUT);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  pinMode(BUTTON_PIN_5, INPUT_PULLUP);
  lcd.init();  // Initialize the lcd
  lcd.noBacklight();
  lcd.noDisplay();
  Serial.begin(9600);
}

void loop()
{
  //power saving mode
  LowPower.idle(SLEEP_1S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_ON, SPI_OFF, USART0_ON, TWI_ON);

  lcd.setCursor(0, 0);
  lcd.print("s:");
  lcd.print(screen_mode[i_display]);
  lcd.print(",");
  lcd.print("p:");
  lcd.print(pump_mode[i_pump]);
  elapsed=millis()-pump_start_time;
  if (elapsed<pump_work_time and digitalRead(RELAY_PIN_6)==HIGH) {digitalWrite(RELAY_PIN_6, LOW);}
  else if (elapsed>pump_work_time and elapsed<pump_cycle_time[i_pump] and digitalRead(RELAY_PIN_6)==LOW) {digitalWrite(RELAY_PIN_6, HIGH);}
  else if (elapsed>pump_cycle_time[i_pump] and digitalRead(RELAY_PIN_6)==HIGH) pump_start_time=millis();

  if (digitalRead(BUTTON_PIN_2) == LOW) //if display button is pressed
  {
    delay(500);
    i_display=(i_display+1)%3; //mode counter for the lcd, each time you press the button, it  switches the mode: 0,1,2
    lcd.clear();
    if (i_display==0) {lcd.display(); lcd.noBacklight();}
    else if (i_display==1) {lcd.display(); lcd.backlight();}
    else if (i_display==2) {lcd.noDisplay(); lcd.noBacklight();}
  }
  if (digitalRead(BUTTON_PIN_3) == LOW) //if pump button is pressed
  {
    delay(500);
    i_pump=(i_pump+1)%4;
    lcd.clear();
  }
}