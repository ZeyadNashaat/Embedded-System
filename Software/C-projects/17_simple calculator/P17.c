#include<stdio.h>
int main()
{
float op1,op2,result;
char x,r;
do
{
printf("Enter op1:\n");
scanf("%f",&op1);
printf("Enter op2:\n");
scanf("%f",&op2);
printf("Enter Operation(+,-,*,/):");
scanf(" %c",&x);
switch (x)
{
	case '+':
	result=op1+op2;
	break;
	case '-':
	result=op1-op2;
	break;
	case '*':
	result=op1*op2;
	break;
	case '/':
	if (op2==0)
	{
		printf("\n");
	}
	else
	{
		result=op1/op2;
	}
	break;
	default:
	printf("Enter one of the four operations\n");
	continue;
}
if (x=='/'&& op2==0)
{
printf("Invalid input, No division by zero\n");
} else
{
printf("result=%0.2f\n",result);
}
printf("Do you want to repeat(r or no):");
scanf(" %c",&r);
}
while(r=='r');
}