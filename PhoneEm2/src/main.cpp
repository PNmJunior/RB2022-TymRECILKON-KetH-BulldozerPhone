
#include <Arduino.h>

#define pinMotorLevyA 8
#define pinMotorLevyB 9
#define pinMotorPravyA 10
#define pinMotorPravyB 11

#define pinCaraKolo0 PA0

#define pTrig1 5
#define pEcho1 4
#define pTrig2 6
#define pEcho2 7


#define smStop 0
#define smVpred 1
#define smVzad -1


void Ridic(int smer = 0,byte levy = 0, byte pravy = 0)
{
  if (smer == smVpred)
  {
    analogWrite(pinMotorLevyA,levy);
    analogWrite(pinMotorLevyB,0);
    analogWrite(pinMotorPravyA, pravy);
    analogWrite(pinMotorPravyB, 0);
  }
  else if (smer == smVzad)
  {
    analogWrite(pinMotorLevyA,0);
    analogWrite(pinMotorLevyB,levy);
    analogWrite(pinMotorPravyA,0 );
    analogWrite(pinMotorPravyB, pravy);
  }
  else
  {
    analogWrite(pinMotorLevyA,0);
    analogWrite(pinMotorLevyB,0);
    analogWrite(pinMotorPravyA,0 );
    analogWrite(pinMotorPravyB, 0);
  }
  
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Ahoj");
  pinMode(pinMotorLevyA, OUTPUT);
  pinMode(pinMotorLevyB,OUTPUT);
  pinMode(pinMotorPravyA, OUTPUT);
  pinMode(pinMotorPravyB,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(pTrig1, OUTPUT);
  pinMode(pEcho1, INPUT);
    pinMode(pTrig2, OUTPUT);
  pinMode(pEcho2, INPUT);
Serial.println("A");

  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
  digitalWrite(13,HIGH);
  delay(1000);
Serial.println("B");
digitalWrite(13,LOW);
Serial.println("C");

  
}


long odezva;
long vzdalenost;
bool ult(int pTrig, int pEcho, int vz = 35)
{
  digitalWrite(pTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pTrig, LOW);
  // pomocí funkce pulseIn získáme následně
  // délku pulzu v mikrosekundách (us)
  odezva = pulseIn(pEcho, HIGH);
  // přepočet získaného času na vzdálenost v cm
  vzdalenost = odezva / 58.31;
  Serial.print(pTrig);
  Serial.print("Vz");
  Serial.println(vzdalenost);
  // pauza 0.5 s pro přehledné čtení
  if (vzdalenost < vz)
  {
    return 1;
  }
  
  return 0;

}




long cas = 0;
long CasB = 0;
long casC = 0;

void loop() {
  //Serial.print("S:");
  cas = millis() /1000;
  //Serial.println(cas);

if(cas ==3)
{
  Serial.println("3");
  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,HIGH);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,HIGH);
}

if(cas ==6)
{
  Serial.println("6");
  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,HIGH);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
  delay(1000);
    digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
  Serial.println("6e");
}


if (cas ==10)
{
  Serial.println("10");
    digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,HIGH);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,HIGH);
}

if (cas ==13)
{
  Serial.println("13");
    digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
}

while (ult(pTrig1, pEcho1) || ult(pTrig2, pEcho2))
{
  Serial.println("U");
  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
  delay(1000);
}



}


/*
// Arduino Měřič vzdálenosti ultrazvukový

// piny pro připojení Trig a Echo z modulu
int pTrig = 5;
int pEcho = 4;
// inicializace proměnných, do kterých se uloží data
long odezva, vzdalenost;
 
void setup() {
  // nastavení pinů modulu jako výstup a vstup
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  // komunikace přes sériovou linku rychlostí 9600 baud
  Serial.begin(9600);
}

void loop()
{
  // nastavíme na 2 mikrosekundy výstup na GND (pro jistotu)
  // poté nastavíme na 5 mikrosekund výstup rovný napájení
  // a poté opět na GND
  digitalWrite(pTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pTrig, LOW);
  // pomocí funkce pulseIn získáme následně
  // délku pulzu v mikrosekundách (us)
  odezva = pulseIn(pEcho, HIGH);
  // přepočet získaného času na vzdálenost v cm
  vzdalenost = odezva / 58.31;
  Serial.print("Vzdalenost je ");
  Serial.print(vzdalenost);
  Serial.println(" cm.");
  // pauza 0.5 s pro přehledné čtení
  delay(500);
}

*/