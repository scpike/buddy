
const int out1 = 2;
const int out2 = 3;

const int out3 = 4;
const int out4 = 5;
int enA = 9;

const int rightButtonPin = 6;
const int fwdButtonPin = 7;
const int leftButtonPin = 8;
const int backButtonPin = 12;
const int headlightPin = 11;
const int ledOut = 13;
const int speedSensorPin = A0;    // select the input pin for the potentiometer
int speedSensorValue = 0;  // variable to store the value coming from the sensor
int powerValue = 0;

int enB =10;

void setup() {
  // put your setup code here, to run once:
  pinMode(out1, OUTPUT);      
  pinMode(out2, OUTPUT);      
  pinMode(out3, OUTPUT);      
  pinMode(out4, OUTPUT);      
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  pinMode(rightButtonPin, INPUT);     
   pinMode(leftButtonPin, INPUT);      
  pinMode(fwdButtonPin, INPUT);      

  pinMode(backButtonPin, INPUT);      
  pinMode(headlightPin, OUTPUT);
  pinMode(ledOut, OUTPUT);      

  //analogWrite(headlightPin, HIGH);
}

int headlightState = 0;
void headlightToggle() {
  if (headlightState == 0) {
   digitalWrite(headlightPin, HIGH);
   headlightState = 1;
  } else {
   digitalWrite(headlightPin, LOW);
   headlightState = 1;
  }
}

void headlightOn() {
  analogWrite(headlightPin, powerValue);
}

void headlightOff() {
  analogWrite(headlightPin, 0);
}

void headlightFlash() {
  digitalWrite(headlightPin, LOW);
  
  digitalWrite(headlightPin, HIGH);
  digitalWrite(headlightPin, LOW);
}

void off() {
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
}

void forward() {
    off();
    headlightOn();
    digitalWrite(out1, HIGH);
    digitalWrite(out3, HIGH);
}

void back() {
    off();
   // headlightOff();
    digitalWrite(out2, HIGH);
    digitalWrite(out4, HIGH);
}


void spinr() {
    off();
    digitalWrite(out1, HIGH);
    digitalWrite(out4, HIGH);
}

void spinl() {
    off();
    digitalWrite(out2, HIGH);
    digitalWrite(out3, HIGH);
}

int fwdButtonState = 0;         // variable for reading the pushbutton status
int backButtonState = 0;         // variable for reading the pushbutton status
int leftButtonState = 0;         // variable for reading the pushbutton status
int rightButtonState = 0;         // variable for reading the pushbutton status

void loop() {

   fwdButtonState = digitalRead(fwdButtonPin);
   backButtonState = digitalRead(backButtonPin);
   leftButtonState = digitalRead(leftButtonPin);
   rightButtonState = digitalRead(rightButtonPin);
   speedSensorValue = analogRead(speedSensorPin);    
   powerValue =  map(speedSensorValue, 0, 1023, 0, 255);

   analogWrite(enA, powerValue);
   analogWrite(enB, powerValue);
   analogWrite(headlightPin, powerValue);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (fwdButtonState == HIGH) {     
    // turn LED on:    
    forward();
    digitalWrite(ledOut, HIGH);
    delay(30);
  } 
  else if (backButtonState == HIGH) {
    // turn LED off:
    back();
    digitalWrite(ledOut, HIGH);
    delay(30);
  } 
    else if (rightButtonState == HIGH) {
    digitalWrite(ledOut, HIGH);
    spinr();
    delay(30);
  } else if (leftButtonState == HIGH) {
    digitalWrite(ledOut, HIGH);
    delay(30);
    spinl();
    } 
    else {  
    off();
    delay(30);
    digitalWrite(ledOut, LOW);
  }
}
