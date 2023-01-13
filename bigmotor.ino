

#define M1_RPWM 2
#define M1_LPWM 3
#define M1_REN 4
#define M1_LEN 5

#define M2_RPWM 8
#define M2_LPWM 9
#define M2_REN 10
#define M2_LEN 11


#include <Servo.h>

#define  HORIZONTALSERVOPIN 12
#define  VERTICALSERVOPIN 13

Servo HorizontalServo;  // create servo object to control a servo
Servo VerticalServo;  // create servo object to control a servo



// possible button states
// on and off state buttons, if random button is on then the rest are ignored

//bool lLeft = false;
//bool lRight = false;
//bool lCenter = false;
//bool lHorizontalRandom =false;
//
//int nLow = 0;
//int nMedium = 0;
//int nHigh = 0;
//bool lVerticalRandom = false;
//

// current positions from the last throw
int nCurrentHorizontal = -1;
int nCurrentVertical = -1;



void setup() {

  Serial.begin(9600);

  HorizontalServo.attach(HORIZONTALSERVOPIN);  // attaches the servo on pin  to the servo object
  VerticalServo.attach(VERTICALSERVOPIN);  // attaches the servo on pin  to the servo object

  // put your setup code here, to run once:
  pinMode(M1_RPWM,OUTPUT);
  pinMode(M1_LPWM,OUTPUT);
  pinMode(M1_LEN,OUTPUT);
  pinMode(M1_REN,OUTPUT);

  // direction
  digitalWrite(M1_REN,HIGH);
  digitalWrite(M1_LEN,HIGH);


  pinMode(M2_RPWM,OUTPUT);
  pinMode(M2_LPWM,OUTPUT);
  pinMode(M2_LEN,OUTPUT);
  pinMode(M2_REN,OUTPUT);

  // direction
  digitalWrite(M2_REN,HIGH);
  digitalWrite(M2_LEN,HIGH);
  
  
  Warmup();

}





void Warmup()
{
  
  Serial.println ("WARMUP in 5 seconds");
  delay(5000);
     

  // motor direction may change based upon future options
  // start slow and bring up to speed
  
  int nMin = 10;
  int nMax = 100;
  int nSpeed = nMin;

  Serial.println ("motor 1");
  while (true)
  {

    nSpeed += 30;

    Serial.println (nSpeed);

    analogWrite(M1_RPWM,nSpeed);
    analogWrite(M1_LPWM,0);
    
    delay(1000);
    
    if (nSpeed > nMax)
      break;

  }

//
//
//  Serial.println ("motor 2");
//
//  nSpeed = nMin;
//
//  while (true)
//  {
//
//    nSpeed += 30;
//
//    Serial.println (nSpeed);
//
//    analogWrite(M2_RPWM,nSpeed);
//    analogWrite(M2_LPWM,0);
//    
//    delay(1000);
//    
//    if (nSpeed > nMax)
//      break;
//
//  }
//



//  
//
//  // servos
//  
//  Serial.println("sweep horizontal");
//  
//  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    HorizontalServo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(40);                       // waits 15ms for the servo to reach the position
//  }
//
//  for (int pos = 180; pos != 90; pos -= 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    HorizontalServo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(40);                       // waits 15ms for the servo to reach the position
//  }
//
//  nCurrentHorizontal = 90;
//
//
//  Serial.println("sweep vertical");
//  
//  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    VerticalServo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(40);                       // waits 15ms for the servo to reach the position
//  }
//
//  for (int pos = 180; pos != 90; pos -= 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    VerticalServo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(40);                       // waits 15ms for the servo to reach the position
//  }
//
//  nCurrentVertical = 0;

  Serial.println ("EXITING WARMUP");

}







void MovePosition(int nHorizontal, int nVertical)
{

  // optmize once working well


  if (nHorizontal != nCurrentHorizontal)
    {

      int pos = nCurrentHorizontal;
      int nIncrement = 1;
      if (nCurrentHorizontal > nHorizontal)
      {
          nIncrement = -1;
          Serial.println("go lower");
      }


      for (pos = nCurrentHorizontal; pos != nHorizontal; pos += nIncrement) { 
        // in steps of 1 degree
        HorizontalServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 15ms for the servo to reach the position        
      }

    
      if (pos == nHorizontal)
      {
        nCurrentHorizontal = nHorizontal;
        Serial.println("exit hor");
//        break;
      }

      
//      for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//        // in steps of 1 degree
//        HorizontalServo.write(pos);              // tell servo to go to position in variable 'pos'
//        delay(10);                       // waits 15ms for the servo to reach the position
//
//        if (pos == nHorizontal)
//        {
//          nCurrentHorizontal = nHorizontal;
//          Serial.println("exit hor");
//          break;
//        }
//         
//      }
    
    }



  
  if (nVertical != nCurrentVertical)
    {
      for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        VerticalServo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(10);                       // waits 15ms for the servo to reach the position

        if (pos == nVertical)
        {
          nCurrentVertical = nVertical;
          Serial.println("exit vert");
          break;
        }
         
      }
    
    }

}




bool Throw()
{
  return true;
}



void loop() {
//
//  Serial.println("90");
//  MovePosition(90,180);
//  delay(5000);
//
//  
//  Serial.println("0");
//  MovePosition(0,50);
//  delay(5000);
//  
//  Serial.println("135");
//  MovePosition(135,180);
//  delay(5000);
//
//
//  Serial.println("45");
//  MovePosition(45,100);
//  delay(5000);
//
//  
//  
//  Serial.println("180");
//  MovePosition(180,16);
//  
//  
//  
//  Serial.println("90");
//  MovePosition(90,0);
//  delay(5000);
//
//
//  Serial.println("home 0");
//  MovePosition(0,0);
//  delay(5000);

//
//
//
//  Serial.println("motor 1 50");
//  analogWrite(M1_RPWM,50);
//  analogWrite(M1_LPWM,0);
//  delay(1000);
//  
//
//  Serial.println("motor 1 100");
//  analogWrite(M1_RPWM,100);
//  analogWrite(M1_LPWM,0);
//  delay(1000);
//  
//
//
//  Serial.println("motor 1 150");
//  analogWrite(M1_RPWM,150);
//  analogWrite(M1_LPWM,0);
//  delay(1000);
//
//
//
//  Serial.println("motor 1 200");
//  analogWrite(M1_RPWM,200);
//  analogWrite(M1_LPWM,0);
//  delay(1000);
//
//
//
//  Serial.println("motor 1 255");
//  analogWrite(M1_RPWM,255);
//  analogWrite(M1_LPWM,0);
//  delay(5000);
//
//
//
//
//
//
//
//
//  Serial.println("motor 2 50");
//  analogWrite(M1_RPWM,50);
//  analogWrite(M1_LPWM,0);
//  delay(1000);
//  
//
//  Serial.println("motor 2 100");
//  analogWrite(M1_RPWM,100);
//  analogWrite(M1_LPWM,0);
//  delay(1000);
//  
//
//
//  Serial.println("motor 2 150");
//  analogWrite(M1_RPWM,150);
//  analogWrite(M1_LPWM,0);
//  delay(1000);
//
//
//
//  Serial.println("motor 2 200");
//  analogWrite(M1_RPWM,200);
//  analogWrite(M1_LPWM,0);
//  delay(1000);
//
//
//
//  Serial.println("motor 2 255");
//  analogWrite(M1_RPWM,255);
//  analogWrite(M1_LPWM,0);
//  delay(5000);
//
//
//
//
// 
//
//  Serial.println("main motor off");
//  analogWrite(M1_RPWM,0);
//  analogWrite(M1_LPWM,0);
//
//  analogWrite(M2_RPWM,0);
//  analogWrite(M2_LPWM,0);
//



  Serial.println("20 seconds to exit");
  
  delay(10000);


  Serial.println("main motor off");
  analogWrite(M1_RPWM,0);
  analogWrite(M1_LPWM,0);

  analogWrite(M2_RPWM,0);
  analogWrite(M2_LPWM,0);


  delay(1000);
 
  Serial.println("bottom");
  
  exit(0);


//  basic logic
//
//  read current settings
//
//  horizontal
//  
//    is random  button pushed
//    is left button pushed
//    is middle button pushed
//    is right button pushed
//   
//    move horizontally based on settings
//    
//  
//  vertical 
//  
//    is random  button pushed
//    is low button pushed
//    is middle button pushed
//    is high button pushed
//   
//    move vertically based on settings
//    
//  
//  ready to throw sensor?
//
//  pause based on setting, use timer not delay
//
//  throw (release ball to wheel)
//
//  go back to read settings again

}
