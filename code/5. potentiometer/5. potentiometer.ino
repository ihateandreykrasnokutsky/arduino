void setup()
{
  pinMode (14,INPUT);
  pinMode(8,OUTPUT);
}

void loop()
{
  int val=analogRead(14);
  digitalWrite(8,HIGH);
  delay(val);
  digitalWrite(8,LOW);
  delay(val);
}
