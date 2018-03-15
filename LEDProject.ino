const int sensorpin = A0;
const int rpin = 10;
const int gpin = 9;
const int bpin = 8;
int  rval, gval, bval;
float degCold;

void setup() {
  // put your setup code here, to run once:

  degCold = 0;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  float volts, degC;
  volts = analogRead(sensorpin) * 0.004882814;
  //degC = 6;
  degC = (volts  - .5) * 100; //calculates the temperature
  Serial.print("degC ");
  Serial.println(degC);

  if (degC > 25.00) //if the temperature is higher than 25c, set the color to purple
  {
    rval = 255;
    gval = 0;
    bval = 255;
  }
  if (degC < 25.00 && degC > 20.00) //if the temperature is lower than 25 and higher than 20, set the color to red
  {
    rval = 255;
    gval = 0;
    bval = 0;    
  }
  //if the temperature is lower than 20 and higher than 15, set the color to yellow
  //if the temperature is lower than 15 and higher than 10, set the color to green
  //if the temperature is lower than 10 and higher than 5, set the color to blue
  //if the temperature is lower than 5, set the color to white

  analogWrite(rpin, rval); //writes colour values to LED at end of loop
  analogWrite(gpin, gval);
  analogWrite(bpin, bval);

  delay(10000);//waits 10 seconds until running the program again
}



