#define RELAY6 9
#define RELAY5 8
#define RELAY4 7
#define RELAY3 6

#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

float P1;
float P2;
float P3;
float P4;


void setup() {
  pinMode(RELAY6,OUTPUT);
  pinMode(RELAY5,OUTPUT);
  lcd.begin(16,2);
  digitalWrite(RELAY6,LOW);
  digitalWrite(RELAY5,LOW);
  digitalWrite(RELAY4,LOW);
  digitalWrite(RELAY5,LOW);
}

void loop() {
  digitalWrite(RELAY6,HIGH);
  
  int sensorValue = analogRead(A0);
  float v1 = sensorValue * (0.005);
  
  if (v1>=5 || v1<0.4) {
    relay5();
  }
  else {
    P1=(4.699* log (v1))-43.12;
    lcd.setCursor(0,0);
    lcd.print("Tegangan=");
    lcd.setCursor(0,1);
    lcd.print("Daya=");
    lcd.setCursor(10,0);
    lcd.print(v1);
    lcd.setCursor(6,1);
    lcd.print(P1);
    delay(500);
  }
}

void relay5() {
  digitalWrite(RELAY5,HIGH);
  int sensorValue = analogRead(A0);
  float v2 = sensorValue * (5.0 / 1023.0);
  if (v2>=5 || v2<0.4) {
    relay4();
  }
  else {
  P2=(4.382* log (v2))-32.37;
  lcd.setCursor(0,0);
  lcd.print("Tegangan=");
  lcd.setCursor(0,1);
  lcd.print("Daya=");
  lcd.setCursor(10,0);
  lcd.print(v2);
  lcd.setCursor(6,1);
  lcd.print(P2);
  delay(500);
  }
}

void relay4() {
  digitalWrite(RELAY5,HIGH);
  digitalWrite(RELAY4,HIGH);
  int sensorValue = analogRead(A0);
  float v3 = sensorValue * (5.0 / 1023.0);
  if (v3>=5 || v3<0.4) {
    relay3();
  }
  else {
  P3=(4.359* log (v3))-22.28;
  lcd.setCursor(0,0);
  lcd.print("Tegangan=");
  lcd.setCursor(0,1);
  lcd.print("Daya=");
  lcd.setCursor(10,0);
  lcd.print(v3);
  lcd.setCursor(6,1);
  lcd.print(P3);
  delay(500);
  }
}

void relay3() {
  digitalWrite(RELAY5,HIGH);
  digitalWrite(RELAY4,HIGH);
  digitalWrite(RELAY3,HIGH);
  int sensorValue = analogRead(A0);
  float v4 = sensorValue * (5.0 / 1023.0);
  if (v4>=5 || v4<0.4) {
    delay(500);
    lcd.clear();
    lcd.print("Sorry!");
  }
  else {
  P4=(4.368* log (v4))-12.23;
  lcd.setCursor(0,0);
  lcd.print("Tegangan=");
  lcd.setCursor(0,1);
  lcd.print("Daya=");
  lcd.setCursor(10,0);
  lcd.print(v4);
  lcd.setCursor(6,1);
  lcd.print(P4);
  delay(500);
  }
}


