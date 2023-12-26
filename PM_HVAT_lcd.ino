#include <Servo.h>
#include <LiquidCrystal.h>
char Command = 'S';


#define SPEED_1      5 
#define LEFT       4 
#define SPEED_2      6
#define RIGHT        7

Servo klesh;
//экран
constexpr uint8_t PIN_RS = 10;
constexpr uint8_t PIN_EN = 11;
constexpr uint8_t PIN_DB4 = 12;
constexpr uint8_t PIN_DB5 = 13;
constexpr uint8_t PIN_DB6 = A0;
constexpr uint8_t PIN_DB7 = 8;
LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_DB4, PIN_DB5, PIN_DB6, PIN_DB7);
void setup() {
  //экран
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);

 for (int i = 4; i < 8; i++) {     
    pinMode(i, OUTPUT);
  }
Serial.begin(9600);
klesh.attach(9);
}

void loop() {
Serial.println("Hello");
 Command = Serial.read(); 
if(Command == 'l'){
  lcd.command(0b101010);
  lcd.clear();
  lcd.print("left");
  digitalWrite(RIGHT, LOW);
  analogWrite(SPEED_2, 0);
  Serial.println("Motor 1");
  digitalWrite(LEFT, HIGH);
  analogWrite(SPEED_1, 255);
  delay(50);
  Command = 't'; 
}

if (Command =='r') {
  lcd.command(0b101010);
  lcd.clear();
  lcd.print("right");
  digitalWrite(LEFT, LOW);
  analogWrite(SPEED_1, 0);
  Serial.println("Motor 2");
  digitalWrite(RIGHT, HIGH);
  analogWrite(SPEED_2, 255);
  delay(50);
  Command = 't';  
}

if (Command == 'f'){
  lcd.command(0b101010);
  lcd.clear();
  lcd.print("forward");
  digitalWrite(LEFT, HIGH);
  analogWrite(SPEED_1, 255);
  Serial.println("Motor 3");
  digitalWrite(RIGHT, HIGH);
  analogWrite(SPEED_2, 255);
  delay(50);
  Command = 't'; 
}

if (Command == 'b'){
  lcd.command(0b101010);
  lcd.clear();
  lcd.print("back");
  digitalWrite(LEFT, LOW);
  analogWrite(SPEED_1, 255);
  Serial.println("Motor 3");
  digitalWrite(RIGHT, LOW);
  analogWrite(SPEED_2, 255);
  delay(50);
  Command = 't'; 
 }
 if (Command == 's'){
  lcd.command(0b101010);
  lcd.clear();
  lcd.print("stop");
  digitalWrite(LEFT, LOW);
  analogWrite(SPEED_1, 0);
  Serial.println("Motor 5");
  digitalWrite(RIGHT, LOW);
  analogWrite(SPEED_2, 0);
  delay(50);
  Command = 't'; 
 }
 if (Command == 'o'){
  lcd.command(0b101010);
  lcd.clear();
  lcd.print("open");
  klesh.write(0);
  delay(100);
  klesh.write(90);
  Command = 't';
 }
 if (Command == 'c'){
  lcd.command(0b101010);
  lcd.clear();
  lcd.print("close");
  klesh.write(180);
  delay(100);
  klesh.write(90);
  Command = 't';
 }
}
