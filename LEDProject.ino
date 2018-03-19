/*
 * Written by Alex Horn
 */

const int sensorpin = A0;
const int rpin = 10;
const int gpin = 9;
const int bpin = 11;
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
  volts = analogRead(sensorpin) * 0.004882814;//reads the voltage from the temperature sensor
  
  degC = (volts  - .5) * 100; //calculates the temperature
  Serial.print("degC ");
  Serial.println(degC);

  if (degC > 25.00) //if the temperature is higher than 25c, set the color to purple
  {
    rval = 255;
    gval = 0;
    bval = 140;
  }
  if (degC < 25.00 && degC > 20.00) //if the temperature is lower than 25 and higher than 20, set the color to red
  {
    rval = 255;
    gval = 0;
    bval = 0;
  }
  if (degC < 20.00 && degC > 15.00) //if the temperature is lower than 20 and higher than 15, set the color to yellow
  {
    rval = 255;
    gval = 50;
    bval = 0;
  }
  if (degC < 15.00 && degC > 10.00)//if the temperature is lower than 15 and higher than 10, set the color to green
  {
    rval = 0;
    gval = 255;
    bval = 0;
  }
  if (degC < 10.00 && degC > 5.00)//if the temperature is lower than 10 and higher than 5, set the color to blue
  {
    rval = 0;
    gval = 0;
    bval = 255;
  }

  if (degC < 10.00 && degC > 5.00)//if the temperature is lower than 5, set the color to white
  {
    rval = 255;
    gval = 255;
    bval = 255;
  }
  analogWrite(rpin, rval); //writes colour values to LED at end of loop
  analogWrite(gpin, gval);
  analogWrite(bpin, bval);

  delay(5000);//waits 5 seconds until running the program again
}



