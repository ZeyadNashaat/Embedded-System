#include<stdio.h>

void print_name(int x);
void print_name(int x)
{
	printf("My name is Zeyad Mohamed \n My school is MENG");
	printf("The result coming from print is %d",x+2);
}

void main(void)
{
	printf("Hello World");
	print_name(3);
}
