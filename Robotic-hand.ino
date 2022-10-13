#include <Servo.h>
 
  int Test_Flag=0;//change to 1 to 
//print sensors values without moving servos

Servo thumb_servo;
Servo index_servo;
Servo middle_servo;
Servo ring_servo;
Servo little_servo;
//----------- Flex sensor ranges ---------
  int min_thumb = 340;
  int max_thumb = 420;
  int min_index = 300;
  int max_index = 365;
  int min_middle = 240;
  int max_middle = 310;
  int min_ring = 260;
  int max_ring = 350;
  int min_little = 580;
  int max_little = 630;

void setup()
{

  Serial.begin(9600);
  
  //------------- Sensors pins ---------------------
  pinMode(A0,INPUT); //Thumb finger flex sensor
  pinMode(A1,INPUT); //Index finger flex sensor
  pinMode(A2,INPUT); //Middle finger flex sensor
  pinMode(A3,INPUT); //Ring finger flex sensor
  pinMode(A4,INPUT); //Little finger flex sensor

//------------- Servos pins ---------------------
  thumb_servo.attach(3); //thumb finger servo motor
  index_servo.attach(5); //index finger servo motor
  middle_servo.attach(6); //middle finger servo motor
  ring_servo.attach(9); //ring finger servo motor
  little_servo.attach(10); //little finger servo motor

//------------------------------------------------
  
}

void loop()
{

//------------- Read fingers angles--------------
  int thumb_f = analogRead(A0);
  int index_f = analogRead(A1);
  int middle_f = analogRead(A2);
  int ring_f = analogRead(A3);
  int little_f = analogRead(A4);
  //----------- Print Sensors values-------------
  Serial.println(thumb_f);
  Serial.print("\t");
  Serial.println(index_f);
  Serial.print("\t\t");
  Serial.println(middle_f);
  Serial.print("\t\t\t");
  Serial.println(ring_f);
  Serial.print("\t\t\t\t");
  Serial.println(little_f);

  if (Test_Flag == 1){
  goto theEnd;
  }
//---------------- Map the values to angles-------- 
  int thumb_angle = map (thumb_f, min_thumb, max_thumb,150, 0);
  int index_angle = map (index_f, min_index, max_index,0, 150);
  int middle_angle = map (middle_f, min_middle, max_middle,0, 150);
  int ring_angle = map (ring_f, min_ring, max_ring,0, 150);
  int little_angle = map (little_f, min_little, max_little,0, 150);//*****
//--------------- Sending angles to servos -----------
  thumb_servo.write(thumb_angle);//****
  index_servo.write(index_angle);
  middle_servo.write(middle_angle);
  ring_servo.write(ring_angle);
  little_servo.write(little_angle);
//  
  theEnd:{}
}
