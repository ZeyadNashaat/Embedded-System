const int TestPins=6;
const int TestArr[TestPins]={3,5,6,9,10,11};
void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<TestPins;i++)
  {
    pinMode(TestArr[i],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
   for (int i=0;i<TestPins;i++)
   {
    digitalWrite(TestArr[i],HIGH);
    delay(1000);
   }
   for (int i=0;i<TestPins;i++)
   {
    digitalWrite(TestArr[i],LOW);
    delay(1000);
   }

}
