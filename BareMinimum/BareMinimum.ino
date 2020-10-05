
const int out1 = 2;
const int out2 = 3;

const int out3 = 4;
const int out4 = 5;
int enA = 9;
int enB =10;

void setup() {
  // put your setup code here, to run once:
  pinMode(out1, OUTPUT);      
  pinMode(out2, OUTPUT);      
  pinMode(out3, OUTPUT);      
  pinMode(out4, OUTPUT);      
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
}

void off() {
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);

}

void forward() {
    off();
    digitalWrite(out1, HIGH);
    digitalWrite(out3, HIGH);
}

void back() {
    off();
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

void loop() {
  // put your main code here, to run repeatedly: 
  	analogWrite(enA, 50);
	analogWrite(enB, 50);

forward();
delay(2000);
back();
delay(2000);
spinr();
delay(500);
spinl();
delay(500);
 off();
 dlay(10000);
}
