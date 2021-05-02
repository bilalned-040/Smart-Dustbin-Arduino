#include <Servo.h>

Servo myservo;
const int trig1 = 9;
const int echo1 = 8;

const int trig2 = 3;
const int echo2 = 2;

const int led = 12;

long duration1;
int dist1;

long duration2;
int dist2;

void setup()
{
  myservo.attach(7);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(echo2, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(led, OUTPUT);
  myservo.write(0);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  duration1 = pulseIn(echo1, HIGH, 2000);
  dist1 = duration1 * 0.034 / 2;

  if (dist1 > 0)
  {
    digitalWrite(trig2, LOW);
    delayMicroseconds(2);
    digitalWrite(trig2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2, LOW);

    duration2 = pulseIn(echo2, HIGH, 2000);
    dist2 = duration2 * 0.034 / 2;
    //Serial.println(dist2);
    if (dist2 == 0)
    {
      digitalWrite(led, LOW);
      myservo.write(90);
      Serial.print("OPENED... ");
      Serial.print("A Person Detected At ");
      Serial.print(dist1);
      Serial.println(" cm");
      Serial.println("WAITING");
      delay(3000);
      myservo.write(0);
      Serial.println("CLOSED");
      Serial.println();
      Serial.println();
    }
    else
    {
      digitalWrite(led, HIGH);
      Serial.println("Trash Full");
      myservo.write(0);
      Serial.println();
      Serial.println();
      delay(3000);
      digitalWrite(led, LOW);

    }
  }
  else
  {
    digitalWrite(led,LOW);
    myservo.write(0);
  }
  delay(300);

}