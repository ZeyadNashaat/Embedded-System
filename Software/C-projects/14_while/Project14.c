#include<stdio.h>
int main()
{
int x;
printf("Enter the answer of 3x4:");
scanf("%d",&x);
while (x!=12)
{
printf("Wrong answer, enter another answer:");
scanf("%d",&x);
}
printf("Thank You");
}
