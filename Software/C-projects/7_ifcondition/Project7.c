#include<stdio.h>
int main()
{
int x,y;
printf("Please enter your working hours:\n");
scanf("%d",&x );
if(x<40)
{
y=x*50-x*5;
}
if(x>=40)
{
y=x*50;
}
printf("your salary =%d",y);
}
