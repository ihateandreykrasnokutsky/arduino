#include<iarduino_RTC.h>//iarduino_RTC-1.3.4/examples/gettime
iarduino_RTC watch(RTC_DS1302,5,3,4);//(RST,CLK,DAT)
int i;
unsigned int s,m,h;//sec,min,hour,day
unsigned long t14,t15,t16,t17;//starting timers for the buttons
int ss6=0;
bool ss7=0,ss8=0,ss9=0;//switching state (changing by the buttons)
int ibc=0;//indicator blinking counter, how much times you want to blink after pressing any button
void setup()
{
  for(i=14;i<=17;i++)pinMode(i,INPUT_PULLUP);//analog pins are now digital button pins
  for(i=6;i<=9;i++)
  {
    pinMode(i,OUTPUT);//relay pins
    digitalWrite(i,LOW);//high signal for the relay to turn off  
  }
  Serial.begin(9600);
  watch.begin();
  watch.period(10);//communication with the clock module takes much time, reducing program's speed
  //watch.settime(0,55,19,19,12,20,6);//sec,min,hour,day,month,year,day of week
}

void growLightProgram1806(unsigned int s,int relaypin)
{
  analogWrite(relaypin,25);
  //if(s>=0 and s<=30)digitalWrite(relaypin,HIGH);
  //else if(s>=31 and s<60)digitalWrite(relaypin,LOW);
}
void growLightProgram1212(unsigned int s,int relaypin)
{
  analogWrite(relaypin,200);
  //if(s>=0 and s<=30)digitalWrite(relaypin,HIGH);
  //else if(s>=31 and s<60)digitalWrite(relaypin,LOW);
  
}

void fanProgram(int s,int freq,int relaypin)
{
  if(s%freq==0)digitalWrite(relaypin,HIGH);
  else if(s%freq!=0)digitalWrite(relaypin,LOW);
}

void loop()
{
  watch.gettime();
  s=watch.seconds;
  m=watch.minutes;
  h=watch.Hours;

  if(digitalRead(14)==LOW)t14=millis();//if button is pressed, make a checkpoint
  if(millis()-t14==50){ss6++;t14=0;}//if current time-checkpoint==50,change switching state and delete the checkpoint
  if(ss6>2)ss6=0;//3 switching states for pin#6 (0,1,2);
  
  if(digitalRead(15)==LOW)t15=millis();
  if(millis()-t15==50){ss7=!ss7;t15=0;}
    
  if(digitalRead(16)==LOW)t16=millis();
  if(millis()-t16==50){ss8=!ss8;t16=0;}

  if(digitalRead(17)==LOW)t17=millis();
  if(millis()-t17==50){ss9=!ss9;t17=0;}

  if(ss6==1)growLightProgram1806(s,6);//if switching state==1,then program1806 is going
  else if(ss6==2)growLightProgram1212(s,6);
  else if(ss6==0)digitalWrite(6,LOW);//if switching state==0, then program isn't going

  if(ss7==1)fanProgram(s,2,7);
  else if(ss7==0)digitalWrite(7,LOW);

  if(ss8==1)fanProgram(s,3,8);
  else if(ss8==0)digitalWrite(8,LOW);

  if(ss9==1)fanProgram(s,4,9);
  else if(ss9==0)digitalWrite(9,LOW);
}
//позже сделай разветвитель на 5 вольт+GND, а также светодиод+пезистор для analogWrite-индикатора
