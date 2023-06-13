#include<stdio.h>
int main()
{
int ID;
printf("Enter your ID");
scanf("%d",&ID);
switch (ID)
{
case 1234:
printf("welcome Ahmed");
break;
case 5678:
printf("Welcome Youssef");
break;
case 1145:
printf("Welcome Mina");
break;
default:
printf("Wrong ID");
break;
}

}
