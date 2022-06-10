
#include <Arduino.h>
#include <Servo.h>

Servo myServo;
#define pinServo 12

#define pinMotorLevyA 8
#define pinMotorLevyB 9
#define pinMotorPravyA 2
#define pinMotorPravyB 3

#define pinCaraKolo0 PA0

#define pTrig1 5
#define pEcho1 4
#define pTrig2 6
#define pEcho2 7


#define smStop 0
#define smVpred 1
#define smVzad -1


void Ridic(int smer = 0,byte levy = 0, byte pravy = 0, int cas = -1)
{
  Serial.print("Ridic");Serial.print(smer);Serial.print(",");Serial.print(levy);Serial.print(",");Serial.print(pravy);
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
  if (cas > 0)
  {
    delay(cas);
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
  myServo.attach(pinServo);
Serial.println("A");
#define SerMax  170
#define SerMin 0
myServo.write(SerMax);
  digitalWrite(pinMotorLevyA,LOW);
  digitalWrite(pinMotorLevyB,LOW);
  digitalWrite(pinMotorPravyA, LOW);
  digitalWrite(pinMotorPravyB,LOW);
  digitalWrite(13,HIGH);
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


int Smer = 0;
int LevyMot = 0;
int PravyMot = 0;
int CekatMotor = -1;
int Index = 0;


void MMM(int index,long zacatek,int smer = 0, int leviMot = 0, int pravyMot =0)
{
  Serial.print(Index);Serial.print("<");Serial.print(index);Serial.print(",");Serial.print(zacatek);Serial.print("<=");Serial.print(cas);Serial.print(",");Serial.print(smer);Serial.print(",");Serial.println(leviMot);
  if(zacatek <= cas && Index < index)
  {
    Serial.println("AA");
    float i = 2*(float)leviMot;
    Ridic(smer,i,pravyMot);
    Smer = smer;
    LevyMot = leviMot;
    PravyMot = pravyMot;
    Index = index;
  }
  else
  {
    Serial.println("BB");
  }
}


void MMMS(int index,long zacatek,int uhel = 0)
{
  Serial.print(Index);Serial.print("<");Serial.print(index);Serial.print(",");Serial.print(zacatek);Serial.print("<=");Serial.print(cas);Serial.print(",");Serial.print(uhel);
  if(zacatek <= cas && Index < index)
  {
    Serial.println("AA");
      for (int i = SerMax; i >= 0; i-= 10)
{
    myServo.write(i);
    delay(200);
    

}
    Index = index;
  }
  else
  {
    Serial.println("BB");
  }
}

void MMM2()
{
Ridic(Smer,LevyMot,PravyMot);
}

long casMinus = 0;
long casMetrix = 0;
long CasMet(int addtime)
{
  casMetrix += addtime;
  return casMetrix;
}


void loop() {
  //Serial.print("S:");
  cas = (millis() - casMinus);
  //Serial.println(cas);
int ab = 0;
int rych = 100;
MMM(++ab,CasMet(3000),1,rych,rych);

MMM(++ab,CasMet(4000));
MMM(++ab,CasMet(1000),1,200,0);
MMM(++ab,CasMet(1250));//cas zatacky
MMM(++ab,CasMet(1000),1,rych,rych);
MMM(++ab,CasMet(4300));
MMMS(++ab,CasMet(1000),180);

MMM(++ab,CasMet(5000),-1, rych,rych);
MMM(++ab,CasMet(2000));

while (ult(pTrig1, pEcho1) || ult(pTrig2, pEcho2))
{
  long a= millis() + 1000;
  Ridic();
  casMinus += 1000;
  Serial.println("U");
  
  while (millis()< a)
  {
    delay(1);
  }
  
}
MMM2();
casMetrix = 0;
ab =0;
/*
Serial.println(analogRead(A0));
Serial.println(analogRead(A1));
delay(5000);*/
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