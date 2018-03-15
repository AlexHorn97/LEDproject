const int sensorpin = A0;
const int rpin = 10;
const int gpin = 9;
const int bpin = 8;
int  rval1, gval1, bval1, rdiff, gdiff, bdiff;
float degCold;

void setup() {
  // put your setup code here, to run once:

  degCold = 0;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  float volts, degCnew;
  volts = analogRead(sensorpin) * 0.004882814;
  //degCnew = 6;
  degCnew = (volts  - .5) * 100; //calculates the temperature
  Serial.print("degCnew ");
  Serial.println(degCnew);
  
  degCold = degCnew;
  
  delay(1000);
}



