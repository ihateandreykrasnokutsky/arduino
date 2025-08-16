//THE CODE WAS CHANGED AND PROBABLY DOESN'T WORK
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
unsigned long button_2_start_time = 0;
unsigned long button_3_start_time = 0;
unsigned long button_4_start_time = 0;
unsigned long button_5_start_time = 0;
int button2State = HIGH;
int button3State = HIGH;
int button4State = HIGH;
int button5State = HIGH;
const int SCREEN_TIMEOUT = 5000;
const int RELAY_TIMEOUT = 2500;
int button_pressed;

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

  unsigned long minutes = (millis() - startTime) / 60000;
  unsigned long seconds = (millis() - startTime) / 1000;
  unsigned long milliseconds = (millis() - startTime);

  //print uptime
  lcd.setCursor(0, 0);
  lcd.print("Uptime: ");
  lcd.print(minutes);
  lcd.print(" min.");

  //read the states of all buttons
  button2State = digitalRead(BUTTON_PIN_2);
  button3State = digitalRead(BUTTON_PIN_3);
  button4State = digitalRead(BUTTON_PIN_4);
  button5State = digitalRead(BUTTON_PIN_5);


       if (digitalRead(BUTTON_PIN_2) == low) button_pressed=2
  else if (digitalRead(BUTTON_PIN_3) == low) button_pressed=3
  else if (digitalRead(BUTTON_PIN_4) == low) button_pressed=4
  else if (digitalRead(BUTTON_PIN_5) == low) button_pressed=5

  

  //code for the 2nd button
  if (button2State == LOW) {
    button_2_start_time = milliseconds;
    Serial.println("Button 2 PRESSED");
  }
  if (millis() < button_2_start_time + SCREEN_TIMEOUT) {
    lcd.display();
    lcd.backlight();
  } else if (milliseconds == button_2_start_time + SCREEN_TIMEOUT) lcd.clear();
  else {
    lcd.noBacklight();
    lcd.noDisplay();
  }

  //code for the 3rd button
  if (button3State == LOW) {
    button_3_start_time = milliseconds;
    Serial.println("Button 3 PRESSED");
  }
  if (milliseconds < button_3_start_time + RELAY_TIMEOUT) digitalWrite(RELAY_PIN_6, LOW);
  else digitalWrite(RELAY_PIN_6, HIGH);
}