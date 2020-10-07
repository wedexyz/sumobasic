/*

 by ahmed Azouz
  https://www.instructables.com/id/How-to-Make-Ardu...

 Download the lib from here first
  https://github.com/ErickSimoes/Ultrasonic/blob/ma...

*/
#include Ultrasonic.h

Ultrasonic ultrasonic(4,3);

const int IN1=5;
const int IN2=6;
const int IN3=9;
const int IN4=10;
#define IR_sensor_front A0 // front sensor
#define IR_sensor_back A1 // rear senson
int distance ;

void setup() 
{
Serial.begin(9600);
delay (5000); // as per sumo compat roles
}
void loop()
{
  
 int IR_front = analogRead(IR_sensor_front);
 int IR_back = analogRead(IR_sensor_back);
 distance = ultrasonic.read();
 ROTATE(200); // start rotete if (distance < 20){
    Stop();
    while (distance < 20 ) {
    FORWARD(255); 
    distance = ultrasonic.read();
    IR_front = analogRead(IR_sensor_front);
    IR_back = analogRead(IR_sensor_back);
    if ( IR_front > 650 || IR_back > 650 ) { break;}
    delay(10); }
  
  
 if (IR_front < 650 )  // < 650 means white line
   {
   Stop();
   delay (50);
   BACKWARD(255);
   delay (500);
   } 
   
 if (IR_back < 650 )  //
   {
   Stop();
   delay (50);
   FORWARD(255);
   delay (500);
   }
   
   /* ----------- debugging ----------------
  Serial.print(ultrasonic.Ranging(CM));
  Serial.println("cm");
  Serial.println("IR front :");
  Serial.println(IR_front); 
  Serial.println("IR back :");
  Serial.println(IR_back);  
*/ 

} //--------------------------------------------
void FORWARD (int Speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,Speed);
}//--------------------------------------------
void BACKWARD (int Speed){
  //When we want to let Motor To move forward,
  // just void this part on the loop section .
  analogWrite(IN1,0);
  analogWrite(IN2,Speed);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}//--------------------------------------------
void ROTATE (int Speed)
{
  //When we want to let Motor To Rotate ,
  // just void this part on the loop section .
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}//--------------------------------------------
void Stop(){
  //When we want to  Motor To stop ,
  // just void this part on the loop section .
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}
