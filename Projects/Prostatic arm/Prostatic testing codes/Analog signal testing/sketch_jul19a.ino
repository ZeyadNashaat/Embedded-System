const int PotNo=6;
const int PotArr[PotNo]={A0,A1,A2,A3,A4,A5};
int PotVal[PotNo]={0,0,0,0,0,0};
const int LedNo=6;
const int LedArr[LedNo]={3,6,5,9,10,11};
int LedVal[LedNo]={0,0,0,0,0,0};
void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<PotNo;i++)
  {
    pinMode(PotArr[i],INPUT);
    pinMode(LedArr[i],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0;i<PotNo;i++)
  {
    PotVal[i]=analogRead(PotArr[i]);
    LedVal[i]=map(PotVal[i],0,1024,0,255);
    analogWrite(LedArr[i],LedVal[i]);
  }

}
