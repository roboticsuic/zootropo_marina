const int controlPin1 =2;
const int controlPin2 =3;
const int enablePin =9;
const int  directionSwitchPin =4;
const int onOffSwitchStateSwitchPin=5;
const int potPin = A0;
const int LedPin = 1;
int pinLedR=13; //LED RED 
int pinLedG=12; //LED GREEN 
int pinLedB=11; //LED BLUE 
int onOffSwitchState =0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;
int motorEnabled=0;
int motorSpeed=0;
int motorDirection=1;
int i=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1,OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);
  pinMode(LedPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:  
  onOffSwitchState =
    digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState =
    digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/16;
  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }
  if (directionSwitchState !=
  previousDirectionSwitchState) {
  if (directionSwitchState == HIGH) {
    motorDirection = !motorDirection;
    }
  }
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  }
   else {
    analogWrite(enablePin, 0);
  }
  previousDirectionSwitchState =
    directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
    digitalWrite(pinLedR, HIGH); //red   
    digitalWrite(pinLedG, LOW);    
    digitalWrite(pinLedB, LOW);  

    if (motorEnabled==1){
          digitalWrite(pinLedR, LOW); //green   
          digitalWrite(pinLedG, HIGH);    
          digitalWrite(pinLedB, LOW);  
         
    }

  


  }
