#include<stdio.h>
int main()
{
printf("Enter the 10 numbers\n");
int i,sum,num;
float av;
sum=0;
for (i=0;i<10;i++)
{
printf("Number %d:",i+1);
scanf("%d",&num);
sum=sum+num;
}
av=sum/10.0;
printf("Sum=%d\n",sum);
printf("Average=%0.2f",av);
}
