#include<stdio.h>
int Get_Max(int x,int y);
int main()
{
	int num1,num2,result;
	printf("Enter First number\n");
	scanf("%d",&num1);
	printf("Enter second number\n");
	scanf("%d",&num2);
	result=Get_Max(num1,num2);
	printf("Max=%d",result);
}
int Get_Max (int x, int y)
{
	int max;
	max=x>y?x:y;
	return max;
}