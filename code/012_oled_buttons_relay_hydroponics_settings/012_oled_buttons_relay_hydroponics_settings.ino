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
#define PUMP_WORK_TIME

//constants
const unsigned long pump_work_time[]={1000,1000,1000,1000,1000,0};
const unsigned long pump_cycle_time[]={10000,20000,30000,40000,1000,5000};
const unsigned long fan_work_time[]={2000,2000,2000,5000,0};
const unsigned long fan_cycle_time[]={10000,20000,30000,5000,5000};
const uint8_t pump_modes_number=sizeof(pump_work_time)/sizeof(pump_work_time[0]);
const uint8_t fan_modes_number=sizeof(fan_work_time)/sizeof(fan_work_time[0]);
const uint8_t screen_modes_number=3; //no light, only text, text+backlight
//variables
unsigned long startTime = millis();
uint8_t i_display=0; //uint8_t to optimize memory, because it's 1 byte, and int is 2 bytes
uint8_t i_pump=0;
uint8_t i_fan=0;
unsigned long pump_start_time = millis();;
unsigned long fan_start_time = millis();;
unsigned long elapsed_pump;
unsigned long elapsed_fan;

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
  LowPower.idle(SLEEP_1S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_ON, SPI_OFF, USART0_ON, TWI_ON); //power saving mode

  lcd.setCursor(0, 0);
  lcd.print("f:"); lcd.print(fan_work_time[i_fan]/1000); lcd.print("/"); lcd.print(fan_cycle_time[i_fan]/1000); //print fan mode
  lcd.print(",");
  lcd.print("p:"); lcd.print(pump_work_time[i_pump]/1000); lcd.print("/"); lcd.print(pump_cycle_time[i_pump]/1000); //print pump mode
  

  elapsed_pump=millis()-pump_start_time; //code for the pump
  if (elapsed_pump<pump_work_time[i_pump] and digitalRead(RELAY_PIN_6)==HIGH) {digitalWrite(RELAY_PIN_6, LOW);}
  else if (elapsed_pump>pump_work_time[i_pump] and elapsed_fan<pump_cycle_time[i_pump] and digitalRead(RELAY_PIN_6)==LOW) {digitalWrite(RELAY_PIN_6, HIGH);}
  else if (elapsed_pump>pump_cycle_time[i_pump] and digitalRead(RELAY_PIN_6)==HIGH) pump_start_time=millis();

  elapsed_fan=millis()-fan_start_time; //code for the fans
  if (elapsed_fan<fan_work_time[i_fan] and digitalRead(RELAY_PIN_7)==HIGH) {digitalWrite(RELAY_PIN_7, LOW);}
  else if (elapsed_fan>fan_work_time[i_fan] and elapsed_fan<fan_cycle_time[i_fan] and digitalRead(RELAY_PIN_7)==LOW) {digitalWrite(RELAY_PIN_7, HIGH);}
  else if (elapsed_fan>fan_cycle_time[i_fan] and digitalRead(RELAY_PIN_7)==HIGH) fan_start_time=millis();

  if (digitalRead(BUTTON_PIN_2) == LOW) //switch modes if the display button is pressed
  {
    delay(500);
    void loop(); //to start the loop anew with the new mode
    i_display=(i_display+1)%screen_modes_number; //mode counter for the lcd, each time you press the button, it  switches the mode: 0,1,2
    lcd.clear(); //to clear the screen before adding a new text
    if (i_display==0) {lcd.display(); lcd.noBacklight();}
    else if (i_display==1) {lcd.display(); lcd.backlight();}
    else if (i_display==2) {lcd.noDisplay(); lcd.noBacklight();}
  }
  if (digitalRead(BUTTON_PIN_3) == LOW) //switch modes if the pump button is pressed
  {
    delay(500);
    void loop();
    i_pump=(i_pump+1)%pump_modes_number;
    lcd.clear();
  }
  if (digitalRead(BUTTON_PIN_4) == LOW) //switch modes if the fan button is pressed
  {
    delay(500);
    void loop();
    i_fan=(i_fan+1)%fan_modes_number;
    lcd.clear();
  }
}