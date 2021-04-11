#include <Ultrasonic.h>
#include <AFMotor.h>
/*

 by ahmed Azouz
  https://www.instructables.com/id/How-to-Make-Ardu...

 Download the lib from here first
  https://github.com/ErickSimoes/Ultrasonic/blob/ma...

*/

Ultrasonic ultrasonic(47,51);
// ++++++++++++++++++++++++ motor pins in 
 


AF_DCMotor motor3(3);
AF_DCMotor motor2(2);

//  ++++++++++++++++++++++++++++++++
#define IR_sensor_front_right A15 // front sensor
#define IR_sensor_front_left A14 // front sensor

//++++++++++++++++++++++++++++++++++
int distance ;


void setup() 
{
Serial.begin(9600);
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
FORWARD_(255); 
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
