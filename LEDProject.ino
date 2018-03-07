const int sensorpin = A0;
const int rpin = 10;
const int gpin = 9;
const int bpin = 8;
int rval2, gval2, bval2, rval1, gval1, bval1, tempRoundNew, tempRoundOld;
int tempBrackNew, tempBrackOld,tempBracket;
float degCold;

void setup() {
  // put your setup code here, to run once:
  rval1 = 255;
  gval1 = 255;
  bval1 = 255;
  //pinMode(rpin,OUTPUT);
  //pinMode(gpin,OUTPUT);
  //pinMode(bpin,OUTPUT);
  degCold = 0;
  tempBrackOld = 0;

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempRoundOld  = round(degCold);
  tempBrackOld = tempBracketTest(tempRoundOld);
  Serial.print("tempRoundOld ");
  Serial.println(tempRoundOld);
//  analogWrite(rpin, rval1);
//  analogWrite(gpin, gval1);
//  analogWrite(bpin, bval1);//lights the LED
  
  float volts, degCnew;
  volts = analogRead(sensorpin) * 0.004882814;
  //degCnew = 6;
  degCnew = (volts  - .5) * 100; //calculates the temperature
  Serial.print("degCnew ");
  Serial.println(degCnew);

  
  tempRoundNew = round(degCnew); //converts temp to int
  Serial.print("tempRoundNew ");
  Serial.println(tempRoundNew);
  tempBrackNew = tempBracketTest(tempRoundNew);
  Serial.print("tempBrackNew ");
  Serial.println(tempBrackNew);
  
  degCold = degCnew;
  delay(1000);
}
int tempBracketTest(int temp)
{
  switch (temp)
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4: //for temperature 0 to 4
      tempBracket = 0;
      break;
    case 5:
    case 6:
    case 7://for temperature 5 to 7
      tempBracket = 1;
      break;
    case 8:
    case 9:
    case 10://for temperature 8 to 10
      tempBracket = 2;
      break;
    case 11:
    case 12:
    case 13://for temperature 11 to 13
      tempBracket = 3;
      break;
    case 14:
    case 15:
    case 16: //for temperature 14 to 16
      tempBracket = 4;
      break;
    case 17:
    case 18:
    case 19: //for temperature 17 to 19
      tempBracket = 5;
      break;
    case 20:
    case 21:
    case 22: //for temperature 20 to 22
      tempBracket = 6;
      break;
    case 23:
    case 24:
    case 25://for temperature 23 to 25
      tempBracket = 7;
      break;
    default:
      tempBracket = 8;
      break;
  }
}


