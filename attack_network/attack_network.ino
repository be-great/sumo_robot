#include <AFMotor.h>
/*

 by ahmed Azouz
  https://www.instructables.com/id/How-to-Make-Ardu...

 Download the lib from here first
  https://github.com/ErickSimoes/Ultrasonic/blob/ma...

*/

// defines pins numbers
const int trigPin =51;
const int echoPin = 47;
// defines variables
long duration;
int distance;
// ++++++++++++++++++++++++ motor pins in 
 


AF_DCMotor motor3(3);
AF_DCMotor motor2(2);

//  ++++++++++++++++++++++++++++++++
#define IR_sensor_front_right A15 // front sensor
#define IR_sensor_front_left A14 // front sensor

//++++++++++++++++++++++++++++++++++

void setup() 
{
Serial.begin(9600);
//altersonic
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//motor3.setSpeed(200);
//motor2.setSpeed(200);
motor3.run(RELEASE);
motor2.run(RELEASE);

delay (5000); // as per sumo compat roles
}
void loop()
{
  
 int IR_front_right = analogRead(IR_sensor_front_right);
 int IR_front_left = analogRead(IR_sensor_front_left);
 
 distance = altersonic();
 // it doesn't need delay because of the condition 
 //Stop();
 Serial.println(distance);
  while (distance < 24 && distance >0 ) {
  FORWARD_(255); 
  distance = altersonic();
  IR_front_right = analogRead(IR_sensor_front_right);
  IR_front_left = analogRead(IR_sensor_front_left);
  
  if ( IR_front_right > 990 || IR_front_left > 990) { break;}  // stop after bushing the car 
  delay(10); }

ROTATE(200);
delay(90);

if (IR_front_right > 990 || IR_front_left > 990 )  // < 650 means white line
 {
 Stop();
 delay (50);
 BACKWARD_(255);
 delay (500);
 ROTATE(200); // start rotete if (distance < 20){
 delay(500);
 } 
 
/*if (IR_back_right < 700 || IR_back_left < 700 )  //
 {
 Stop();
 delay (50);
 FORWARD(255);
 delay (500);
 }
 
 // ----------- debugging ----------------
Serial.print(ultrasonic.Ranging(CM));
Serial.println("cm");
Serial.println("IR front :");
Serial.println(IR_front); 
Serial.println("IR back :");
Serial.println(IR_back);  
*/ 
} //--------------------------------------------
void FORWARD_ (int Speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  motor3.run(FORWARD);
  motor2.run(FORWARD);
  motor3.setSpeed(Speed);
  motor2.setSpeed(Speed);

}//--------------------------------------------
void ROTATE (int Speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  motor3.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor2.setSpeed(Speed);
}//--------------------------------------------
void BACKWARD_ (int Speed)
{
  //When we want to let Motor To Rotate ,
  // just void this part on the loop section .
  motor3.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.setSpeed(Speed);
  motor2.setSpeed(Speed);
}//--------------------------------------------
void Stop(){
  //When we want to  Motor To stop ,
  // just void this part on the loop section .
  motor3.run(RELEASE);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor2.setSpeed(0);
}
long altersonic(){
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH,8000);
  // Calculating the distance
  distance= duration*0.034/2;
 
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance); 
return distance;


  
  
  }
