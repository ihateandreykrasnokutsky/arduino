#include<iarduino_RTC.h>//iarduino_RTC-1.3.4/examples/gettime

iarduino_RTC watch(RTC_DS1302,11,13,12);//(RST,CLK,DAT)
int i;
unsigned int s,m,h;//sec,min,hour,day
unsigned long t14,t15,t16,t17;//starting timers for the buttons
int ss7=0,ss8=0,ss9=0,ss10=0;//switching state (changing by the buttons)
int ledcounter;//countdown timer for LED indicators

void setup()
{
  for(i=2;i<=6;i++)pinMode(i,OUTPUT);//LED indicators
  for(i=14;i<=17;i++)pinMode(i,INPUT_PULLUP);//analog pins are now digital button pins
  for(i=7;i<=10;i++)pinMode(i,OUTPUT);//relay pins,LOW signal means relay is off
  watch.begin();
  watch.period(10);//communication with the clock module takes much time, reducing program's speed
  //watch.settime(0,55,19,19,12,20,6);//sec,min,hour,day,month,year,day of week, don't uncomment, or time'll reset
  for(i=2;i<=6;i++)//check all indicator LEDS
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW); 
  }
  for(i=7;i<=10;i++)//check all relay pins
  {
    digitalWrite(i,HIGH);
    delay(1000);
    digitalWrite(i,LOW);
  }
}

void growLightProgram1806(unsigned int h,int relaypin)//grow light program #1
{
  if(h>=6 and h<=23)digitalWrite(relaypin,HIGH);
  else if(h>=0 and h<6)digitalWrite(relaypin,LOW);
}

void growLightProgram1212(unsigned int h,int relaypin)//grow light program#2
{
  if(h>=6 and h<18)digitalWrite(relaypin,HIGH);
  else if(h>=18 and h<=23 and h>=0 and h<6)digitalWrite(relaypin,LOW);
}

void blinking(int ledpin,unsigned long leddelay)//not actual blinking,just lighting
{
  if(ledcounter>0)
  {
    if(millis()%(leddelay*2)==0)digitalWrite(ledpin,HIGH);
    if(millis()%1000==0)ledcounter--;
  }
  if(ledcounter==0)digitalWrite(ledpin,LOW);
}

void loop()
{
  watch.gettime();
  s=watch.seconds;
  m=watch.minutes;
  h=watch.Hours;

  if(digitalRead(14)==LOW)t14=millis();//if button is pressed, make a checkpoint
  if(millis()-t14==50){ss7++;t14=0;ledcounter=10;}//if current time-checkpoint==50,change switching state and delete the checkpoint,also increase LED indicators' countdown timer
  if(ss7>3)ss7=0;//the total of 4 switching states(0,1,2,3)
  
  if(digitalRead(15)==LOW)t15=millis();
  if(millis()-t15==50){ss8=!ss8;t15=0;ledcounter=10;}
    
  if(digitalRead(16)==LOW)t16=millis();
  if(millis()-t16==50){ss9=!ss9;t16=0;ledcounter=10;}

  if(digitalRead(17)==LOW)t17=millis();
  if(millis()-t17==50){ss10=!ss10;t17=0;ledcounter=10;}

  if(ss7==1){growLightProgram1806(h,8);if(millis()%1000==0)blinking(2,100);}//if switching state==1,then program1806 is going+wait till the next seconds and do "blinking"
  if(ss7==2){growLightProgram1212(h,8);if(millis()%1000==0)blinking(3,100);}
  if(ss7==3){digitalWrite(8,HIGH);blinking(2,100);blinking(3,100);}//turn everything on, all LEDs indicators blink
  if(ss7==0){digitalWrite(8,LOW);digitalWrite(2,LOW);digitalWrite(3,LOW);}//if switching state==0,then turn relays and LEDs off

  if(ss8==1){digitalWrite(7,HIGH);if(millis()%1000==0)blinking(4,100);}//7 and 8 inputs on the relay are messed, so I fixed it in the program
  if(ss8==0){digitalWrite(7,LOW);digitalWrite(4,LOW);}

  if(ss9==1){digitalWrite(9,HIGH);if(millis()%1000==0)blinking(5,100);}
  if(ss9==0){digitalWrite(9,LOW);digitalWrite(5,LOW);}

  if(ss10==1){digitalWrite(10,HIGH);if(millis()%1000==0)blinking(6,100);}
  if(ss10==0){digitalWrite(10,LOW);digitalWrite(6,LOW);}
}
//future advice: do program good since the start, create arrays, if possible, create variables for each pin, make cycles with those arrays
