#include <Keypad.h> // Keypad Library
#include <Servo.h> //Servo library

const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2, 1}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
char customKey;
String command = "";

String manager1 = "1#";
String manager2 = "2#";
String manager3 = "3#";
String manager4 = "4#";
String manager5 = "5#";

int manager1State = 1;
int manager2State = 1;
int manager3State = 1;
int manager4State = 1;
int manager5State = 1;

int manager1Motor = 9;
int manager2Motor = 10;
int manager3Motor = 11;
int manager4Motor = 12;
int manager5Motor = 13;

int manager1LED = A0;
int manager2LED = A1;
int manager3LED = A2;
int manager4LED = A3;
int manager5LED = A4;


Servo managerServo;  //Servo name is managerServo

void setup(){
  Serial.begin(9600);

      pinMode(manager1LED, OUTPUT);
      pinMode(manager2LED, OUTPUT);
      pinMode(manager3LED, OUTPUT);
      pinMode(manager4LED, OUTPUT);
      pinMode(manager5LED, OUTPUT);

//      managerServo.attach(9);

      
}
  
void loop(){

  while(customKey != '#'){
       customKey = customKeypad.getKey();
       if(customKey){
           command+=customKey;
        }
       delay(50); 
  }
  
  String currentCommand = command;
  command = "";
  customKey='N';
    
  Serial.println(currentCommand);

  if(currentCommand.equals(manager1)){
      Serial.println("1");
      turnLED(manager1LED, manager1State);
      turnServo(manager1Motor, manager1State);
      manager1State *= (-1);
    }
  else if(currentCommand.equals(manager2)){
      Serial.println("2");
      turnLED(manager2LED, manager2State);
      turnServo(manager2Motor, manager2State);
      manager2State *= (-1);
    }
  else if(currentCommand.equals(manager3)){
      Serial.println("3");
      turnLED(manager3LED, manager3State);
      turnServo(manager3Motor, manager3State);
      manager3State *= (-1);
    }   
  else if(currentCommand.equals(manager4)){
      Serial.println("4");
      turnLED(manager4LED, manager4State);
      turnServo(manager4Motor, manager4State);
      manager4State *= (-1);
    }   
  else if(currentCommand.equals(manager5)){
      Serial.println("5");
      turnLED(manager5LED, manager5State);
      turnServo(manager5Motor, manager5State);
      manager5State *= (-1);
    }

    
}

void turnServo(int managerPin, int directionId){
  Serial.println("rotatin ");
  managerServo.attach(managerPin);
  if(directionId == 1){
      managerServo.write(0);
    }

    else{
      managerServo.write(180);
      
      }
    delay(500);
    managerServo.detach();
  }

  void turnLED(int managerPin, int directionId){
    Serial.println("turning LED on");
    if(directionId == 1){
        digitalWrite(managerPin, HIGH);      
      }
    else{
      digitalWrite(managerPin, LOW);      
      }
  delay(1000);
    }

    

