
int i=0,freq8=1000,freq9=1300,freq10=4100,freq11=5000;//counter i and delays for each LED
unsigned long t8=millis(),t9=millis(),t10=millis(),t11=millis();//cycle's start times
void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for(i=2;i<=5;i++)//input pins (buttons) with pull-up resistors
  {
    pinMode(i,INPUT_PULLUP);
  }
  for(i=8;i<=11;i++)//output pins(LEDs)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
}

void switchoff()//swtich off everything, with timers going on
{
  while(digitalRead(2)==HIGH)
  {
    for(i=8;i<=11;i++)digitalWrite(i,LOW);//switches off all leds while button is off
    if(millis()-t8==freq8*2)t8=millis();//variable t continues to renew
    if(millis()-t9==freq9*2)t9=millis();//as it would be in the normal loop function
    if(millis()-t10==freq10*2)t10=millis();
    if(millis()-t11==freq11*2)t11=millis();
  }
  loop();//if button is pressed, "while" stops and loop starts
}

void restart()//restarts all timers
{
  t8=t9=t10=t11=millis();
  loop();//and starts loop function
}

void loop()//signs < instead of == are made for [switchoff-loop] smooth transition
{
  if(millis()-t8<freq8)digitalWrite(8,HIGH);//timers for all buttons
  else if(millis()-t8<freq8*2)digitalWrite(8,LOW);
  else if(millis()-t8==freq8*2)t8=millis(); 

  if(millis()-t9<freq9)digitalWrite(9,HIGH);
  else if(millis()-t9<freq9*2)digitalWrite(9,LOW);
  else if(millis()-t9==freq9*2)t9=millis();

  if(millis()-t10<freq10)digitalWrite(10,HIGH);
  else if(millis()-t10<freq10*2)digitalWrite(10,LOW);
  else if(millis()-t10==freq10*2)t10=millis();

  if(millis()-t11<freq11)digitalWrite(11,HIGH);
  else if(millis()-t11<freq11*2)digitalWrite(11,LOW);
  else if(millis()-t11==freq11*2)t11=millis();

  if(digitalRead(3)==LOW)switchoff();
  if(digitalRead(4)==LOW)restart();
}//button 2 is turning on (from swtich off), button 3 is switch off, button 4 is restart timers;
