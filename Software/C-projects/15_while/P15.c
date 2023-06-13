#include<stdio.h>
int main()
{
int x,i, result;
printf("Enter number");
scanf("%d",&x);
i=0;
while (i<=10)
{
result=x*i;
printf("%d x %d =%d\n",x,i,result);
i++;
}
}