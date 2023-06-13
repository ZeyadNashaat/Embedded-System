#include<stdio.h>
int main()
{
int num,bit,result;
printf("Enter a number:");
scanf("%d",&num);
printf("Enter bit number");
scanf("%d",&bit);
if ((bit>=0)&&(bit<31))
{
//result= num|(1<<bit); set
//result= num&(~(1<<bit));//clear
result=num^(1<<bit);
printf("Setting=%d",result);
}
else
{
	printf("Enter no of bit between 0-31");
}
}
