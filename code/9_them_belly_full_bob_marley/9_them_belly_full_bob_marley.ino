#include<pitches.h>
int i=0;
int dur1=1000,dur2=500,dur3=1000/3,dur4=250,dur8=125,dur16=62.5;
int pin=2;
void setup()
{
  pinMode(pin,OUTPUT);
}
void loop()
{
  for(i=0;i<2;i++)
  {
    tone(pin,NOTE_E4,dur4);delay(dur4);
    tone(pin,NOTE_E5,dur4);delay(dur4);
    tone(pin,NOTE_D5,dur4);delay(dur4);
    tone(pin,NOTE_C5,dur4);delay(dur2);
    tone(pin,NOTE_A4,dur4);delay(dur4);
    tone(pin,NOTE_G4,dur4);delay(dur4);
    tone(pin,NOTE_F4,dur4);delay(dur2);
    tone(pin,NOTE_F4,dur4);delay(dur4);
    tone(pin,NOTE_E4,dur4);delay(dur1);
  
    tone(pin,NOTE_E4,dur4);delay(dur4);
    tone(pin,NOTE_E5,dur4);delay(dur4);
    tone(pin,NOTE_D5,dur4);delay(dur4);
    tone(pin,NOTE_C5,dur4);delay(dur2);
    tone(pin,NOTE_C5,dur4);delay(dur4);
    tone(pin,NOTE_C5,dur4);delay(dur4);
    tone(pin,NOTE_F5,dur4);delay(dur2);
    tone(pin,NOTE_F5,dur4);delay(dur4);
    tone(pin,NOTE_E5,dur4);delay(dur1);
  }
  tone(pin,NOTE_C5,dur4);delay(dur4);//them belly full but we hungry
  tone(pin,NOTE_E5,dur4);delay(dur4);
  tone(pin,NOTE_D5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur2);
  tone(pin,NOTE_A4,dur4);delay(dur4);
  tone(pin,NOTE_G4,dur4);delay(dur4);
  tone(pin,NOTE_F4,dur4);delay(dur2+dur4);
  tone(pin,NOTE_E4,dur4);delay(dur1);

  tone(pin,NOTE_C4,dur4);delay(dur4);//a hungry mob is a angry mob
  tone(pin,NOTE_E5,dur4);delay(dur4);
  tone(pin,NOTE_D5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur2);
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_F5,dur4);delay(dur2);
  tone(pin,NOTE_F5,dur4);delay(dur4);
  tone(pin,NOTE_E5,dur4);delay(dur1);

  tone(pin,NOTE_C5,dur4);delay(dur4);//a rain a fall but the dirt it tough
  tone(pin,NOTE_E5,dur4);delay(dur4);
  tone(pin,NOTE_D5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur2);
  tone(pin,NOTE_A4,dur4);delay(dur4);
  tone(pin,NOTE_G4,dur4);delay(dur4);
  tone(pin,NOTE_F4,dur4);delay(dur2);
  tone(pin,NOTE_F4,dur4);delay(dur4);
  tone(pin,NOTE_E4,dur4);delay(dur1);

  tone(pin,NOTE_C5,dur4);delay(dur4);//a pot a cook but the food no 'nough
  tone(pin,NOTE_E5,dur4);delay(dur4);
  tone(pin,NOTE_D5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur2);
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_F5,dur4);delay(dur2);
  tone(pin,NOTE_F5,dur4);delay(dur4);
  tone(pin,NOTE_E5,dur4);delay(dur1);
  
  for(i=0;i<2;i++)//you're gonna dance to jah music dance, we're gonna dance to jah music dance
  {
    tone(pin,NOTE_C5,dur4);delay(dur4);
    tone(pin,NOTE_D5,dur4);delay(dur4);
    tone(pin,NOTE_C5,dur4);delay(dur4);
    tone(pin,NOTE_E5,dur4);delay(dur2);
    tone(pin,NOTE_D5,dur4);delay(dur4);
    tone(pin,NOTE_C5,dur4);delay(dur4);
    tone(pin,NOTE_D5,dur4);delay(dur2);
    tone(pin,NOTE_E5,dur4);delay(dur2);
    tone(pin,NOTE_C5,dur4);delay(dur1);
  }

  tone(pin,NOTE_A4,dur4);delay(dur4);//forget your troubles and dance
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_A4,dur4);delay(dur4);
  tone(pin,NOTE_D5,dur4);delay(dur2);
  tone(pin,NOTE_E5,dur4);delay(dur2);
  tone(pin,NOTE_B4,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur2);delay(dur1);

  tone(pin,NOTE_A4,dur4);delay(dur4);//forget your sorrow and dance
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_D5,dur4);delay(dur2);
  tone(pin,NOTE_E5,dur4);delay(dur2);
  tone(pin,NOTE_B4,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur2);delay(dur1);

  for(i=0;i<2;i++)
  {
    tone(pin,NOTE_A4,dur4);delay(dur4);//forget your sickness and dance, forget your weakness and dance
    tone(pin,NOTE_C5,dur4);delay(dur4);
    tone(pin,NOTE_C5,dur4);delay(dur4);
    tone(pin,NOTE_F5,dur4);delay(dur2);
    tone(pin,NOTE_E5,dur4);delay(dur2);
    tone(pin,NOTE_B4,dur4);delay(dur4);
    tone(pin,NOTE_C5,dur2);delay(dur1);
  }

  tone(pin,NOTE_E5,dur4);delay(dur2);//cost of living get so high
  tone(pin,NOTE_E5,dur4);delay(dur2);
  tone(pin,NOTE_E5,dur4);delay(dur4);
  tone(pin,NOTE_E5,dur4);delay(dur2);
  tone(pin,NOTE_F5,dur4);delay(dur2);
  tone(pin,NOTE_F5,dur4);delay(dur2);
  tone(pin,NOTE_E5,dur4);delay(dur1);

  tone(pin,NOTE_E5,dur4);delay(dur2);//reach and poor they start to cry
  tone(pin,NOTE_E5,dur4);delay(dur2);
  tone(pin,NOTE_E5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur2);
  tone(pin,NOTE_D5,dur4);delay(dur2);
  tone(pin,NOTE_C5,dur4);delay(dur2);
  tone(pin,NOTE_E5,dur4);delay(dur1);

  tone(pin,NOTE_E5,dur4);delay(dur2);//now the weak must get strong
  tone(pin,NOTE_G5,dur4);delay(dur4);
  tone(pin,NOTE_E5,dur4);delay(dur2+dur4);
  tone(pin,NOTE_F5,dur4);delay(dur2);
  tone(pin,NOTE_F5,dur4);delay(dur2);
  tone(pin,NOTE_E5,dur4);delay(dur1);

  tone(pin,NOTE_C5,dur4);delay(dur4);//they say "oh,what a tribulation"
  tone(pin,NOTE_D5,dur4);delay(dur2);
  tone(pin,NOTE_E5,dur4);delay(dur2+dur4);
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_D5,dur4);delay(dur4);
  tone(pin,NOTE_E5,dur4);delay(dur4);
  tone(pin,NOTE_C5,dur4);delay(dur4);
  tone(pin,NOTE_D5,dur4);delay(dur2);
  tone(pin,NOTE_C5,dur4);delay(dur1);
  
  delay(100000);
}
