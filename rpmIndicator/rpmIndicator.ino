#define throttle A5

int pitLimiter = 2;
int gearUpButton = 0;
int gearDownButton = 1;
int latchPin = 4;
int clockPin = 3;
int dataPin = 5;
int leds = 13;
int gear = 1;
//a,b,c,d,e,f,g         abcdefg.
byte gearsArray [8] = {B00001010,//r
                       B00101010,//n
                       B01100000,//1
                       B11011010,//2
                       B11110010,//3
                       B01100110,//4
                       B10110110,//5
                       B10111110,//6
                       };

int numberOfLedsOn = 0;
int previousRevs = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pitLimiter, INPUT_PULLUP);
  pinMode(gearUpButton, INPUT_PULLUP);
  pinMode(gearDownButton, INPUT_PULLUP);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  writeGearToDisplay(gear);
 
  
}

void loop() {
  // put your main code here, to run repeatedly:
 int currentRevs = analogRead(throttle);
 int revsLights = currentRevs /57;
 int revLightsOn = 0;
 int revLightsPin = 13;
 int timeDelay = 1200 - currentRevs;
 if(revsLights > 8) revsLights = 8;
 if(currentRevs >= previousRevs)
 {
   while(revLightsOn <= revsLights)
   {
    digitalWrite(revLightsPin,HIGH);
    revLightsOn ++;
    revLightsPin --;
    delay(timeDelay);
    if(digitalRead(pitLimiter) ==LOW) 
      pitLimiterOn();
    if(digitalRead(gearUpButton) ==LOW)
    {
      delay(250);
      gearUp();
    }
    if(digitalRead(gearDownButton)==LOW)
    {
      delay(250);
      gearDown();
    }
   }
  
 }else
 {
  while(revLightsOn >= revsLights)
  { 
    digitalWrite(revLightsPin,LOW);
    revLightsOn --;
    revLightsPin ++;
    delay(timeDelay);
    if(digitalRead(pitLimiter) ==LOW) 
  pitLimiterOn();
 if(digitalRead(gearUpButton) ==LOW)
 {
  delay(250);
  gearUp();
 }
 if(digitalRead(gearDownButton)==LOW)
 {
  delay(250);
  gearDown();
 }
  }
 }
 previousRevs = currentRevs;
 if(digitalRead(pitLimiter) ==LOW) 
  pitLimiterOn();
 if(digitalRead(gearUpButton) ==LOW)
 {
  delay(250);
  gearUp();
 }
 if(digitalRead(gearDownButton)==LOW)
 {
  delay(250);
  gearDown();
 }
  
  
}

void pitLimiterOn()
{
  resetRPMLeds();
  int timer = 0;
  while(true)
  {
    if(digitalRead(pitLimiter)==LOW)
      break;
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    if(digitalRead(pitLimiter)==LOW)
      break;
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    delay(500);
    if(digitalRead(pitLimiter)==LOW)
      break;
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    if(digitalRead(pitLimiter)==LOW)
      break;
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    delay(500);
    if(digitalRead(pitLimiter)==LOW)
      break;
    
  }
  resetRPMLeds();
  
  
  
}

void gearUp()
{
  if(gear == 8)
  {
    writeGearToDisplay(gear);
  }else
  {
    gear ++;
    writeGearToDisplay(gear);
    resetRPMLeds();
  }
}
void gearDown()
{
  if(gear == 0)
  {
    writeGearToDisplay(gear);
  }else
  {
    gear --;
    writeGearToDisplay(gear);
    resetRPMLeds();
  }
}

void resetRPMLeds()
{
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  numberOfLedsOn = 0; 
}

void writeGearToDisplay(byte gear)
{
   // set the latchPin to low potential, before sending data
  digitalWrite(latchPin, LOW);
     
  // the original data (bit pattern)
  shiftOut(dataPin, clockPin, LSBFIRST, gearsArray[gear]);  
 
  // set the latchPin to high potential, after sending data
  digitalWrite(latchPin, HIGH); 
}
