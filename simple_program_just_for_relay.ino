unsigned long t=millis();//period start timer
const unsigned long e7=10000000;//exponent e^7
const unsigned long h18=6.48*e7,h12=4.32*e7,h24=8.64*e7,h1=0.36*e7;//times in milliseconds
unsigned long tp;//time passed since a last 24 hour period

void setup()
{
  for(int i=2;i<=5;i++)pinMode(i,OUTPUT);
}

void loop()
{
  tp=millis()-t;
  if(tp<h18 and tp>=0)digitalWrite(2,HIGH);//LEDs 18/6
  if(tp<h24 and tp>=h18)digitalWrite(2,LOW);

  if((tp>=0 and tp<h1)or(tp>=h1*6 and tp<h1*7)or(tp>=h1*12 and tp<h1*13)or(tp>=h1*18 and tp<h1*19))digitalWrite(3,LOW);//inner fan#1 is on
  else digitalWrite(3,HIGH);//inner fan is off
  
  digitalWrite(4,HIGH);//outer fan#2 is on
  
  digitalWrite(5,HIGH);//empty relay, turn it off (switched off relays means that previous 3 circuits are shorted)

  if(tp>=h24)t=millis();
}
