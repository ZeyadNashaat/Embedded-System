#include<stdio.h>
int main()
{
float num1,num2;
printf("Enter first number");
scanf("%f",&num1);
printf("Enter second number");
scanf("%f",&num2);
float sum,sub,mul,div;
sum=num1+num2;
sub=num1-num2;
mul=num1*num2;
div=num1/num2;
printf("Addition=%f\n",sum);
printf("subtraction=%f\n",sub);
printf("multiplacation=%f\n",mul);
printf("Division=%f",div);
}
