// connect motor controller pins to Arduino digital pin
// motor one
int enA = 3;
int in1 = 4;
int in2 = 7;
// motor two
int enB = 5;
int in3 = 8;
int in4 = 12;
//ir sensor
int LS=11;
int RS=2;

void setup()
{
// set all the motor control pins to output
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  Serial.begin(9600);
}

void loop()
{
  if(!(digitalRead(LS)) && !(digitalRead(RS)))   // Move Forward
  {
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  Serial.print("forward");
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
   // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  //turn off motor b
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.print("right");
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
   // now turn off motor a
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
   // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  Serial.print("left");
  }
  
  if(digitalRead(LS) && digitalRead(RS))   // stop
  {
    // now turn off motor a and b
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.print("stop");
  }
}
