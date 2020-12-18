int i=0,freq8=500,freq9=1000,freq10=1000,freq11=400;
unsigned long t8=millis(),t9=millis(),t10=millis(),t11=millis();
unsigned long tb2=millis(),tb3=millis(),tb4=millis(),tb5=millis();
void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for(i=2;i<=5;i++)//пины ввода с подтягивающими к питанию резисторами
  {
    pinMode(i,INPUT_PULLUP);
  }
  for(i=8;i<=11;i++)//пины вывода
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
}

void switchoff()
{
  while(digitalRead(3)==HIGH)for(i=8;i<=12;i++)digitalWrite(i,LOW);
    t8=t9=millis();
    loop(); 
}

void loop()
{
  if(millis()-t8==0)digitalWrite(8,HIGH);
  else if(millis()-t8==freq8)digitalWrite(8,LOW);
  else if(millis()-t8==freq8*2)t8=millis();

  if(millis()-t9==0)digitalWrite(9,HIGH);
  else if(millis()-t9==freq9)digitalWrite(9,LOW);
  else if(millis()-t9==freq9*2)t9=millis();

  if(digitalRead(2)==LOW)switchoff();

  //if(millis()-t10==0)digitalWrite(10,HIGH);
  //else if(millis()-t10==freq10)digitalWrite(10,LOW);
  //else if(millis()-t10==freq10*2)t10=millis();

  //if(millis()-t11==0)digitalWrite(11,HIGH);
  //else if(millis()-t11==freq11)digitalWrite(11,LOW);
  //else if(millis()-t11==freq11*2)t11=millis();
}
