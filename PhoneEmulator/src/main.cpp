#include <Arduino.h>

#define pinMotorLevyA PB3
#define pinMotorLevyB PB4
#define pinMotorPravyA PB5
#define pinMotorPravyB PB6

#define pinCaraKolo0 PA0

#define trigPin1 PA9
#define echoPin1 PA10
#define trigPin2 PB8
#define echoPin2 PB7






void setup() {
  // put your setup code here, to run once:
  pinMode(pinMotorLevyA, OUTPUT);
  pinMode(pinMotorLevyB,OUTPUT);
  pinMode(pinMotorPravyA, OUTPUT);
  pinMode(pinMotorPravyB,OUTPUT);
  pinMode(PB13,OUTPUT);


  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
  digitalWrite(PB13,HIGH);
  delay(1000);

digitalWrite(PB13,LOW);

  
}

bool ult(int trigPin, int echoPin,float vzdalenost)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = (duration/2) / 29.1;   //vypočítání v cm
  if (distance < vzdalenost)
  {
    return 1;
  }
  return 0;
  

}


long cas = 0;
long CasB = 0;
long casC = 0;

void loop() {
  long sek = millis() /1000;
if(cas ==3)
{
  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,HIGH);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,HIGH);
}

if(cas ==6)
{
  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,HIGH);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
  delay(1000);
    digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
}


if (cas ==10)
{
    digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,HIGH);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,HIGH);
}

if (cas ==13)
{
    digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
}

while (ult(trigPin1, echoPin1, 25) ||ult(trigPin2, echoPin2, 25))
{
  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
  delay(1000);
}



}