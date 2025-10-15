#include <Servo.h>
Servo myservo; // definition myservo in the servo library
int trigPin = 10; // Trigger
int echoPin = 11; // Echo
long duration, cm, inches;
void setup() {
    // put your setup code here, to run once:
    pinMode(52,OUTPUT) ; //a
    pinMode(53,OUTPUT) ; //b
    pinMode(50,OUTPUT) ; //c
    pinMode(51,OUTPUT); //g
    pinMode(48,OUTPUT); //f
    pinMode(49,OUTPUT); //d
    pinMode(46,OUTPUT); //e
    myservo.attach(3); //servo PWM pin - voltage
    //Serial Port begin
    Serial.begin (9600);
    //Define inputs and outputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
 void func (char b){
    // modify 7 segement
    if(b==0)
    {
      digitalWrite(52,HIGH);
      digitalWrite(53,HIGH) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,LOW);
      digitalWrite(48,HIGH);
      digitalWrite(49,HIGH);
      digitalWrite(46,HIGH);
    }
    else if(b==1)
    {
      digitalWrite(52,LOW);
      digitalWrite(53,HIGH) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,LOW);
      digitalWrite(48,LOW);
      digitalWrite(49,LOW);
      digitalWrite(46,LOW);
    }
    else if(b==2)
    {
      digitalWrite(52,HIGH);
      digitalWrite(53,HIGH) ;
      digitalWrite(50,LOW) ;
      digitalWrite(51,HIGH);
      digitalWrite(48,LOW);
      digitalWrite(49,HIGH);
      digitalWrite(46,HIGH);
    }

    else if(b==3)
    {
      digitalWrite(52,HIGH);
      digitalWrite(53,HIGH) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,HIGH);
      digitalWrite(48,LOW);
      digitalWrite(49,HIGH);
      digitalWrite(46,LOW);
    }
    else if(b==4)
    {
      digitalWrite(52,LOW);
      digitalWrite(53,HIGH) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,HIGH);
      digitalWrite(48,HIGH);
      digitalWrite(49,LOW);
      digitalWrite(46,LOW);
    }
    else if(b==5)
    {
      digitalWrite(52,HIGH);
      digitalWrite(53,LOW) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,HIGH);
      digitalWrite(48,HIGH);
      digitalWrite(49,HIGH);
      digitalWrite(46,LOW);
    }
    else if(b==6)
    {
      digitalWrite(52,HIGH);
      digitalWrite(53,LOW) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,HIGH);
      digitalWrite(48,HIGH);
      digitalWrite(49,HIGH);
      digitalWrite(46,HIGH);
    }
    else if(b==7)
    {
      digitalWrite(52,HIGH);
      digitalWrite(53,HIGH) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,LOW);
      digitalWrite(48,LOW);
      digitalWrite(49,LOW);
      digitalWrite(46,LOW);
    }
    else if(b==8)
    {
      digitalWrite(52,HIGH);
      digitalWrite(53,HIGH) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,HIGH);
      digitalWrite(48,HIGH);
      digitalWrite(49,HIGH);
      digitalWrite(46,HIGH);
    }
    else if(b==9)
    {
      digitalWrite(52,HIGH);
      digitalWrite(53,HIGH) ;
      digitalWrite(50,HIGH) ;
      digitalWrite(51,HIGH);
      digitalWrite(48,HIGH);
      digitalWrite(49,HIGH);
      digitalWrite(46,LOW);
    }
 }

void loop() {
  // put your main code here, to run repeatedly:
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
// Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
digitalWrite(trigPin, LOW);
delayMicroseconds(20);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);

// Read the signal from the sensor: a HIGH pulse whose
// duration is the time (in microseconds) from the sending
// of the ping to the reception of its echo off of an object.
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);

// Convert the time into a distance
cm = (duration/2) / 29.1; // Divide by 29.1 or multiply by 0.0343
inches = (duration/2) / 74; // Divide by 74 or multiply by 0.0135

Serial.print(inches);
Serial.print("in, ");
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(250);

// put your main code here, to run repeatedly:

char N=0;
func(N);

aaa:

digitalWrite(trigPin, LOW);
delayMicroseconds(20);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);

pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
cm = (duration/2) / 29.1;

if (cm<=8 ){



delay(1000); 
myservo.write(0);
N=N+1;
func(N);
delay(3000);
myservo.write(0);
 }
delay(1000);

goto aaa;



}
