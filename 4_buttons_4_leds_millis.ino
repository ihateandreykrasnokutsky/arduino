int i=0,freq=500,pin=8;
unsigned long t8=millis();
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

void loop()
{
  if(millis()-t8==0)digitalWrite(pin,HIGH);//если прошло 0 секунд со сброса, то включение+выбор случайного пина+выбор случайной частоты
  if(millis()-t8==freq)digitalWrite(pin,LOW);//если прошло freq сек. со сброса, то выключение
  if(millis()-t8==freq*2)t8=millis();//если прошло freq*2 сек. со сброса, то сброc времени начала выполнения loop до текущего
}
