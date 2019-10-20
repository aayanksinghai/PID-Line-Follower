// Code for Line Follower Bot having 3 IR Sensors
// Using PID Algorithm 
// This code works on White Background Black Path.

// Initialising Motor Pins
int rightmotor1=10;
int leftmotor1=3;
int rightmotor2=11;
int leftmotor2=5;

// Initialising Sensor Pins
int sensorleft=9;
int sensorcenter=7;
int sensorright=8;

// Sensors Variable
int l1=0;     // left sensor variable
int l2=0;     // center sensor variable
int l3=0;      // right sensor variable

// PID error variables
int f1=1;
int f2=1;
int f3=1;

int j;
//////////////////////////////////////

// Functions for Movement of Bot

void forward()
{
  digitalWrite(rightmotor1,1);
  digitalWrite(rightmotor2,0);
  digitalWrite(leftmotor1,1);
  digitalWrite(leftmotor2,0);

}

void stopp()
{
  digitalWrite(rightmotor1,0);
  digitalWrite(rightmotor2,0);
  digitalWrite(leftmotor1,0);
  digitalWrite(leftmotor2,0);
  
}

void left()
{
  digitalWrite(rightmotor1,1);
  digitalWrite(rightmotor2,0);
  digitalWrite(leftmotor1,0);
  digitalWrite(leftmotor2,0);
  
  
}

void right()
{
  digitalWrite(rightmotor1,0);
  digitalWrite(rightmotor2,0);
  digitalWrite(leftmotor1,1);
  digitalWrite(leftmotor2,0);
}

void pid()
{
  l1=f1;
  l2=f2;
  l3=f3;
  
  
}

void setup()
{

 pinMode(rightmotor1,OUTPUT);
 pinMode(leftmotor1,OUTPUT);
 pinMode(rightmotor2,OUTPUT);
 pinMode(leftmotor2,OUTPUT);

 pinMode(sensorleft,INPUT);
 pinMode(sensorcenter,INPUT);
 pinMode(sensorright,INPUT);

}

void loop()
{
l1=digitalRead(sensorleft);
l2=digitalRead(sensorcenter);
l3=digitalRead(sensorright);


if(l1==1&&l2==1&&l3==1)   //feedback when comes all sensor on white
{

pid();


}

else if(l1==0&&l2==1&&l3==1 || l1==0&&l2==0&&l3==1)   //left turn
{
  left();
}
else if(l1==1&&l2==1&&l3==0||l1==1&&l2==0&&l3==0)  //right turn
{
   right();
}
else if(l1==1&&l2==0&&l3==1)  //go forward straight
{
  forward();
}
else if(l1==0&&l2==0&&l3==0) //stop
{
 stopp();  
  
}


///////////////////////////////////////////////////////////////////
f1=l1;
f2=l2;
f3=l3;        //memory variables
////////////////////////////////////////////////////////////////////
} 
