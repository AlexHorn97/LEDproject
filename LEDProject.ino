const int sensorpin = 0;
const int rpin = 13;
const int gpin = 12;
const int bpin = 11;
int; rval1,rval2,gval1,gval2,bval1,bval2;

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

  float volts,degCnew,degCold;
  volts = getVoltage(sensorpin);

  degCnew = (volts - 0.5) * 100.0;//calculates the temperature
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
