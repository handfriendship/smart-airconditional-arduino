#include <Servo.h>
Servo myServo, AirServo, AirServo2;
//Servo AirServo;
//Servo AirServo2;

int AirServoPin = 12; 
int AirServoPin2 = 13;
int servoPin = 11; //이게 인체감지센서에 달려있는 서보모터
int motionPin = 8;
int angle, angle_step = 1;
int AirAngle;




void setup() {
  myServo.attach(servoPin); // 서보 모터 연결
  AirServo.attach(AirServoPin); // 에어컨 서보 모터 연결
  AirServo2.attach(AirServoPin2);
  Serial.begin(9600);
  pinMode(motionPin, INPUT);
  angle = 60;
  
  myServo.write(angle);
}

int MotionInput1(){
  int value1, value2, value3, value4, value5, value6, value7, value8, value9, value10, value11, value12, value13, value14, value15;
  value1 = digitalRead(motionPin);
  delay(200);
  value2 = digitalRead(motionPin);
  delay(200);
  value3 = digitalRead(motionPin);
  delay(200);
  value4 = digitalRead(motionPin);
  delay(200);
  value5 = digitalRead(motionPin);
  delay(200);
  value6 = digitalRead(motionPin);
  delay(200);
  value7 = digitalRead(motionPin);
  delay(200);
  value8 = digitalRead(motionPin);
  delay(200);
  value9 = digitalRead(motionPin);
  delay(200);
  value10 = digitalRead(motionPin);
  delay(200);
  value11 = digitalRead(motionPin);
  delay(200);
  value12 = digitalRead(motionPin);
  delay(200);
  value13 = digitalRead(motionPin);
  delay(200);
  value14 = digitalRead(motionPin);
  delay(200);
  value15 = digitalRead(motionPin);
  delay(200);

  return (value1 || value2 || value3 || value4 || value5 || value6 || value7 || value8
  || value9 || value10 || value11 || value12 || value13 || value14 || value15);
  
  
}

unsigned long time_current, time_previous;

bool MotionInput2(){
  int interval;
  int value00, value01, value02, value03, value04, value05, value06, value07, value08, value09; 
  int value_00, value_01, value_02, value_03, value_04, value_05, value_06, value_07, value_08, value_09; 
  
  value_00 = value_01 = value_02 = value_03 = value_04 = value_05 = 
  value_06 = value_07 = value_08 = value_09 =0;
  
  time_previous = millis();
  while(interval < 3000){
    value00 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value01 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value02 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value03 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value04 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value05 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value06 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value07 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value08 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    value09 = digitalRead(motionPin);
    if(value00 == 1)
      value_00 = value00;
    
    time_current = millis();
    interval = time_current - time_previous;
    
  }

  
  
  return (value_00 || value_01 || value_02 || value_03 || value_04
  || value_05 || value_06 || value_07 || value_08 || value_09);
  
}

void loop() {
  Serial.println("Let's start with 5 seconds delay, please ready~~");
  //delay(5000);
  
  if(angle < 90){
    
    angle = 60;
    AirAngle = angle;
    myServo.write(angle);
    Serial.println("5 seconds delay");
    delay(5000);
    //bool val1 = MotionInput2();
    while(MotionInput2() == 1){
    //val1 = MotionInput2();    
        Serial.println("Motion detected");
        angle -= 10;
        AirAngle = angle;
        myServo.write(angle);
        //delay(1000);
    }
    Serial.println("Servo Moter of PIR Sensor is end in range of 'angle < 90'");
    Serial.println("5 seconds delay");
    delay(5000);
    
    Serial.print("The value of AirAngle is : ");
    Serial.println(AirAngle);
    Serial.println("It's time the AirServo to be moved !");
    delay(5000);
    AirServo.write(AirAngle);
    
    delay(1000);
    Serial.println("It's time the myServo to be moved to the opposite side after delay of 5 seconds!");
    delay(5000);

    
    angle = 120;
    AirAngle = angle;
    myServo.write(angle);
    Serial.println("5 seconds delay");
    delay(5000);

    //bool val2 = MotionInput2();
    while(MotionInput2() == 1){
        //val2 = MotionInput2();
        Serial.println("Motion detected");
        angle += 10;
        AirAngle = angle;
        myServo.write(angle);
        //delay(1000);
    }
    Serial.println("Servo Moter of PIR Sensor is end in range of 'angle > 90'");
    Serial.println("5 seconds delay");
    delay(5000);
    
    Serial.print("The value of AirAngle is : ");
    Serial.println(AirAngle);
    Serial.println("It's time the AirServo2 to be moved !");
    
    AirServo2.write(AirAngle);
    
    delay(1000);
    Serial.println("When you see this message, our project ends successfully ~!!");
    delay(5000);
  }
  
  else{ // (angle > 90)
    Serial.println("When myServo is located in the opposited side, it checks that area first");
    angle = 120;
    AirAngle = angle;
    myServo.write(angle);
    Serial.println("5 seconds delay");
    delay(5000);

    //bool val3 = MotionInput2();
    while(MotionInput2() == 1){
        //val3 = MotionInput2();
        Serial.println("Motion detected");
        angle += 10;
        AirAngle = angle;
        myServo.write(angle);
        //delay(1000);
    }
    Serial.println("Servo Moter of PIR Sensor is end in range of 'angle > 90'");
    Serial.println("5 seconds delay");
    delay(5000);
    
    Serial.print("The value of AirAngle is : ");
    Serial.println(AirAngle);
    Serial.println("It's time the AirServo2 to be moved !");
    
    AirServo2.write(AirAngle);
    
    delay(1000);
    Serial.println("It's time the myServo to be moved to the opposite side after delay of 2 seconds!");
    delay(2000);
    
  
    angle = 60;
    AirAngle = angle;
    myServo.write(angle);
    Serial.println("5 seconds delay");
    delay(5000);

    //bool val4 = MotionInput2();
    while(MotionInput2() == 1){
        //val4 = MotionInput2();
        Serial.println("Motion detected");
        angle -= 10;
        AirAngle = angle;
        myServo.write(angle);
        //delay(1000);
    }
    Serial.print("The value of AirAngle is : ");
    Serial.println(AirAngle);
    Serial.println("It's time the AirServo to be moved !");
    
    AirServo.write(AirAngle);
    Serial.println("Servo Moter of PIR Sensor is end in range of 'angle < 90'");
    delay(1000);
    Serial.println("When you see this message, our project ends successfully ~!!");
    delay(5000);
    
  }
  delay(6000);
  delay(60000);
}

