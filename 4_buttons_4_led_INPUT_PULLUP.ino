int i=0,j=0,k=0;
void setup()
{
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
  for(i=8;i<=11;i++)
  {
    digitalWrite(i,LOW);
  }
}

void garland(int freq)//функция мигания
{
  for(int i=8;i<=11;i++)
  {
    digitalWrite(i,HIGH);
    delay(freq);
    digitalWrite(i,LOW);
    delay(freq);
  }
}

void loop()
{
  k=j;//переменная для номера ранее зажатой кнопки
  j=0;//переменная для номера зажатой кнопки
  for(i=2;i<=5;i++)
  {
    if(digitalRead(i)==LOW)j=i;//если кнопка зажата (ток идет от питания и подтяг. резистора на землю мимо пина)
  }
  if(j==0)j=k;//если сейчас не нажата кнопка, то текущая кнопка - предыдущая, т.е. состояние сохраняется через ротации программы
  if(j==2)garland(25);
  else if (j==3)garland(50);
  else if(j==4)garland(200);
  else if(j==5)switchoff;
}
