#define  upPin 0
#define downPin 1
#define throttle 2
#define e 13
#define d 12
#define c 11
#define g 10
#define f 9
#define a 8
#define b 7

int gear = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(upPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(upPin) == LOW)
  {
    delay(500);
    gearUp();
  }
  if(digitalRead(downPin)==LOW)
  {
    delay(500);
    gearDown();
  }
  switch(gear){
    case 0:
      reverse();
      break;
    case 1:
      neutral();
      break;
    case 2:
      firstGear();
      break;
    case 3:
      secondGear();
      break;
    case 4:
      thirdGear();
      break;
    case 5:
      fourthGear();
      break;
    case 6:
      fifthGear();
      break;
    case 7:
      sixthGear();
      break;
    case 8:
      seventhGear();
      break;
    case 9:
      eightGear();
      break;
    case 10:
      ninghtGear();
      break;
    default:
      neutral();
      break;
  }
  

}
//Prints out a n on the 7-seg display
//e,g,c on a,b,e,d off
void neutral()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}
//prints out r on 7-seg display
//e, g on a,b,c,d,f off
void reverse()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH); 
}
//prints 1 to 7-seg
// b,c on a,d,e,f,g off
void firstGear()
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);  
}
//prints 2 to 7-seg
//a,b,d,e,g on c,f off
void secondGear()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);   
}
//prints 3 to 7-seg
//a,b,c,d,g on e,f off
void thirdGear()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);   
}
//prints 4 to 7-seg
//b,c,g,f on a,d,e off
void fourthGear()
{
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH); 
}
//prints 5 to 7-seg
//a,f,g,c,d on b,e off
void fifthGear()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);   
}
//print 6 to 7-seg
//a,c,d,e,f,g on b off
void sixthGear()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);   
}
//print 7 to 7-seg
//a,b,c on d,e,f,g off
void seventhGear()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);   
}
//prints 8 to 7-seg
// all on
void eightGear()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);  
}
//prints 9 to the 7-seg
//a,b,c,d,f,g on e off
void ninghtGear()
{
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH); 
}
//incraments the gear variable
int gearUp()
{
  if(gear == 10)
  {
    return 10;
  }else
  {
    return gear ++;
  }
}
//decrements the gear variable
int gearDown()
{
  if(gear ==0)
  {
    return 0;
  }
  else{
    return gear --;
  }
}
