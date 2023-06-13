#include<stdio.h>
int main()
{
int x;
int y=1;
printf("Enter a number:");
scanf("%d",&x);
do
{
	if (x==0)
	{break;}
y*=x;
x--;
}
while (x>0);
printf("The factorial =%d",y);
}