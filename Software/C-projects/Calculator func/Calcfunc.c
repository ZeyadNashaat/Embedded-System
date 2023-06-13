#include<stdio.h>
float add(float x,float y); //add prototype.
float subtract(float x, float y);//subtract prototype.
float multiply(float x, float y);//multiply prototype.
float division(float x, float y);//division prototype.
int main()
{
	float op1,op2,z;
	char o,r;
do
{
printf("Enter op1:\n");
scanf("%f",&op1);
printf("Enter op2:\n");
scanf("%f",&op2);
printf("Enter Operation(+,-,*,/):");
scanf(" %c",&o);
switch (o)
{
	case '+':
	z=add(op1,op2);//calling add.
	break;
	case '-':
	z=subtract(op1,op2);//calling  subtract.
	break;
	case '*':
	z= multiply(op1,op2);//calling multiply.
	break;
	case '/':
	if (op2==0)
	{
		printf("\n");
	}
	else
	{
		z= division(op1,op2);//calling division.
	}
	break;
	default:
	printf("\n");
	break;
}
if (o=='/'&& op2==0)
{
printf("Invalid input, No division by zero\n");
}
else if (o!='+'&&o!='-'&&o!='*'&&o!='/')
{
printf("Enter one of the four operations\n");
}
else
{
printf("result=%0.2f\n",z);
}
printf("Do you want to repeat(r or no):");
scanf(" %c",&r);
}
while(r=='r');
}
	
float add(float x, float y) //add denfination.
{
	float result=x+y;
	return result;
}
float subtract(float x, float y) //subtract denfination.
{
	float result=x-y;
	return result;
}
float multiply(float x, float y) //multiply denfination.
{
	float result=x*y;
	return result;
}
float division(float x, float y) //division denfination.
{
	float result=x/y;
	return result;
}