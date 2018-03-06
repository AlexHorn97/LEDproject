const int sensorpin = A0;
const int rpin = 10;
const int gpin = 9;
const int bpin = 8;
int rval2, gval2, bval2, rval1, gval1, bval1;
float degCold;

void setup() {
  // put your setup code here, to run once:
  rval1 = 255;
  gval1 = 255;
  bval1 = 255;
  //pinMode(rpin,OUTPUT);
  //pinMode(gpin,OUTPUT);
  //pinMode(bpin,OUTPUT);
  degCold = 5;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(rpin, rval1);
  analogWrite(gpin, gval1);
  analogWrite(bpin, bval1);
  float volts, degCnew;
  volts = analogRead(sensorpin) * 0.004882814;
  //degCnew = 6;
  degCnew = (volts  - .5) * 100; //calculates the temperature
  Serial.println(degCnew);
  if (degCnew < 5.0)
  {
    rval2 = 255;
    gval2 = 255;
    bval2 = 255;
    //LED limit white
  }
  if (degCnew > 5.0 && degCnew <= 8.0)
  {
    rval2 = 200;
    gval2 = 200;
    bval2 = 255;
    //Led limit light blue
  }
  if (degCnew > 8.0 && degCnew <= 12.0)
  {
    rval2 = 0;
    gval2 = 0;
    bval2 = 255;
    //Led limit blue
  }
  if (degCnew > 12.0 && degCnew <= 15.0)
  {
    rval2 = 0;
    gval2 = 255;
    bval2 = 255;
    //Led limit teal
  }
  if (degCnew > 15.0 && degCnew <= 18.0)
  {
    rval2 = 0;
    gval2 = 255;
    bval2 = 0;
    //Led limit green
  }
  if (degCnew > 18.0 && degCnew <= 21.0)
  {
    rval2 = 255;
    gval2 = 255;
    bval2 = 0;
    //Led limit yellow
  }
  if (degCnew > 21.0 && degCnew <= 24.0)
  {
    rval2 = 255;
    gval2 = 155;
    bval2 = 0;
    //Led limit orange
  }
  if (degCnew > 24.0)
  {
    rval2 = 255;
    gval2 = 0;
    bval2 = 0;
    //Led limit red
  }

  if (degCnew != degCold)
  {
    if (degCnew > degCold)//if the new temperature is higher than the old one
    {
      while (rval1 != rval2 || gval1 != gval2 || bval1 != bval2) {
        if (rval1 > rval2) //red fade
        {
          rval1 = rval1 - 5;
          

        }
        if (gval1 > rval2) //green fade
        {
          gval1 = gval1 - 5;

          

        }
        if (bval1 > bval2) //blue fade
        {
          bval1 = bval1 - 5;

          
        }
        if (rval1 < rval2) //red fade
        {
          rval1 = rval1 + 5;
          

        }
        if (gval1 < rval2) //green fade
        {
          gval1 = gval1 + 5;

          

        }
        if (bval1 < bval2) //blue fade
        {
          bval1 = bval1 + 5;

          
        }
      }
      Serial.print(rval1);
      Serial.print(gval1);
      Serial.println(bval1);
      analogWrite(rpin, rval1);
      analogWrite(gpin, gval1);
      analogWrite(bpin, bval1);
      delay(100);
    }
    //    if (degCnew < degCold)//if the new temperature is lower than the old one
    //    {
    //            while(rval1 != rval2)//red fade
    //      {
    //        rval1 + 5;
    //
    //      }
    //      while(gval1 != rval2)//green fade
    //      {
    //        gval1 + 5;
    //
    //      }
    //      while(bval1 != bval2)//blue fade
    //      {
    //        bval1 + 5;
    //
    //      }
    //    }
  }

  degCold = degCnew;
  delay(1000);
}


