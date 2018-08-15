#include <SPI.h>
#include <MFRC522.h>

const byte arduino0 = A0;
const byte arduino1 = A1;
const byte arduino2 = A2;
const byte hall = A3;
const byte maglock = A4;
const byte photo = A5;
const byte buzzer = 12;
bool flag0, flag1, flag2, flag3;
bool penalty1, penalty2, penalty3;
bool ard0, ard1, ard2, hallState, ard4;
bool buzz0, buzz1, buzz2, buzz3, buzz4;
bool masterArd;
bool unlock;
long unlocked;
int timeout = 5000;
int value0;
//GREEN, GREEN-A, BLUE, BLUE-A, BROWN, BROWN-A, ORANGE-A

void setup() {
  Serial.begin(9600);
  Serial.print("Museum Shelf Master");
  pinMode(arduino0, INPUT);
  pinMode(arduino1, INPUT);
  pinMode(arduino2, INPUT);
  pinMode(hall, INPUT);
  pinMode(photo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(maglock, OUTPUT);
}

void loop() {
  ard0 = digitalRead(arduino0);
  delay(10);
  ard1 = digitalRead(arduino1);
  delay(10);
  ard2 = digitalRead(arduino2);
  delay(10);
  hallState = digitalRead(hall);
  delay(10);
  value0 = analogRead(photo);

  debug();
  unlock = true;
  if(!ard0){
    unlock = false;
    buzz0 = false;
  }
  else{
    if(!buzz0){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      buzz0 = true;
    }
  }
  if(!ard1){
    unlock = false;
    buzz1 = false;
  }
   else{
    if(!buzz1){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      buzz1 = true;
    }
  }
  if(!ard2){
    unlock = false;
    buzz2 = false;
  }
   else{
    if(!buzz2){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      buzz2 = true;
    }
  }
  if(hallState){
    unlock = false;
    buzz3 = false;
  }
   else{
    if(!buzz3){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      buzz3 = true;
    }
  }
  if(value0 >= 200){
    unlock = false;
    buzz4 = false;
  }
   else{
    if(!buzz4){
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      buzz4 = true;
    }
  }

  if(unlock){
    Serial.println("Unlocked!");
    digitalWrite(maglock, HIGH);
//    if(unlocked - millis() > timeout){
//      Serial.println("Delaying 30 Seconds");
//      //digitalWrite(reset, HIGH);
//      delay(30000);
//      //digitalWrite(reset, LOW);
//      unlocked = millis();
//    }
    Serial.println("Door Open!");
  }
  else{
    //Serial.println("Locked");
    digitalWrite(maglock, LOW);
  }
  delay(500);
}

void debug(){
  Serial.print("Arduino0: ");
  Serial.println(ard0);
  Serial.print("Arduino1: ");
  Serial.println(ard1);
  Serial.print("Arduino2: "); 
  Serial.println(ard2);
  Serial.print("HallState: ");
  Serial.println(hallState);
  Serial.print("Photo: ");
  Serial.println(value0);
  /*Serial.print("Flag0: ");
  Serial.println(flag0);
  Serial.print("Flag1: ");
  Serial.println(flag1);
  Serial.print("Flag2: ");
  Serial.println(flag2);
  Serial.print("Flag3: ");
  Serial.println(flag3);

  Serial.print("Penalty1: ");
  Serial.println(penalty1);
  Serial.print("Penalty2: ");
  Serial.println(penalty2);
  Serial.print("Penalty3: ");
  Serial.println(penalty3);*/
}

