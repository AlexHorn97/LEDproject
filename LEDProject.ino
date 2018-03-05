const int sensorpin = 0;
const int rpin = 13;
const int gpin = 12;
const int bpin = 11;
int rval2,gval2,bval2;
float degCold;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(rpin,OUTPUT);
  pinMode(gpin,OUTPUT);
  pinMode(bpin,OUTPUT);
  int rval1 = 255;
  int gval1 = 255;
  int bval1 = 255;
  degCold = 10;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  float volts,degCnew;
  volts = getVoltage(sensorpin);

  degCnew = (volts - 0.5) * 100.0;//calculates the temperature
  
 if (degCnew < 5) 
 {
  rval2 = 255;
  gval2 = 255;
  bval2 = 255;
  //LED limit white
 }
  if (degCnew > 5 && degCnew <= 8) 
 {
  rval2 = 200;
  gval2 = 200;
  bval2 = 255;
  //Led limit light blue
 }
  if (degCnew > 8 && degCnew <= 12) 
 {
  rval2 = 0;
  gval2 = 0;
  bval2 = 255;
  //Led limit blue
 } 
  if (degCnew > 12 && degCnew <= 15) 
 {
  rval2 = 0;
  gval2 = 255;
  bval2 = 255;
  //Led limit teal
 }
   if (degCnew > 15 && degCnew <= 18) 
 {
  rval2 = 0;
  gval2 = 255;
  bval2 = 0;
  //Led limit green
 }
   if (degCnew > 18 && degCnew <= 21) 
 {
  rval2 = 255;
  gval2 = 255;
  bval2 = 0;
  //Led limit yellow
 }
   if (degCnew > 21 && degCnew <= 24) 
 {
  rval2 = 255;
  gval2 = 155;
  bval2 = 0;
  //Led limit orange
 }
   if (degCnew > 24) 
 {
  rval2 = 255;
  gval2 = 0;
  bval2 = 0;
  //Led limit red
 }
  while (degCnew != degCold) 
  {
    if (degCnew > degCold)//if the new temperature is higher than the old one
    {
      
    }
    if (degCnew < degCold)//if the new temperature is lower than the old one 
    {
      
    }
  }
  
  
  delay(1000);
}
float getVoltage(int pin) 
{
    return (analogRead(pin) * 0.004882814);//calculates the voltage
}
