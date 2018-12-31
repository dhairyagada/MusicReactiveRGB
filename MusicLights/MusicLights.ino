

int voltagePin=A0;
int voltageVal=0;

long newVal=0;

String binStr;

String rBin;
String gBin;
String bBin;

int rBinVal,gBinVal,bBinVal;

int r=11;
int g=10;
int b=9;

int rv,gv,bv;

int c=0;

void setup() {
 
pinMode(r, OUTPUT);
pinMode(g, OUTPUT);
pinMode(b, OUTPUT);

Serial.begin(9600);
}

void loop() {
  voltageVal=analogRead(voltagePin);
  //c=c+1;
  //voltageVal=c;
  Serial.print("Voltage Value = ");
  Serial.println(voltageVal);
  voltageToRGB(voltageVal);  
  delay(300);
}

void setrgb(int x, int y, int z)
{
  analogWrite(r,x);
  analogWrite(g,y);
  analogWrite(b,z);
}

String decToBin(int decValue, byte desiredStringLength) {
  
  String hexString = String(decValue, BIN);
  while (hexString.length() < desiredStringLength) hexString = "0" + hexString;
  
  return hexString;
}

int binToDecRGB(int binVal)
{
 switch(binVal)
 {
  case 0: return 0;
          break;
  case 1: return 35;
          break;
  case 10: return 71;
          break;          
  case 11: return 107;
          break;
  case 100: return 143;
          break;  
  case 101: return 179;
          break;
  case 110: return 215;
          break;
  case 111: return 251;
          break;          
  default: return 255;
 }
}
void voltageToRGB(int voltage)
{
  
  binStr=decToBin(voltage,10);

  rBin=binStr.substring(0,3);
  gBin=binStr.substring(3,6);
  bBin=binStr.substring(6,9);

  rBinVal=rBin.toInt();
  gBinVal=gBin.toInt();
  bBinVal=bBin.toInt();

  rv=binToDecRGB(rBinVal);
  gv=binToDecRGB(gBinVal);
  bv=binToDecRGB(bBinVal);

  setrgb(rv,gv,bv);
 
/*  Serial.print("Bin Value = ");
  Serial.println(binStr);  
  Serial.print("R Bin Value = ");
  Serial.print(rBinVal);
  Serial.print("    R Int Value = ");
  Serial.println(r);
  Serial.print("G Bin Value = ");
  Serial.print(gBinVal);
  Serial.print("    G Int Value = ");
  Serial.println(g);
  Serial.print("B Bin Value = ");
  Serial.print(bBinVal);
  Serial.print("    B Int Value = ");
  Serial.println(b);
  */
}
