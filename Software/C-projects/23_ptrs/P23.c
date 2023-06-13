#include<stdio.h>
int main()
{
	int x=10;
	printf("Before:%d\n",x);
	int *ptr=&x;
	*ptr=20;
	printf("After:%d",x);
}