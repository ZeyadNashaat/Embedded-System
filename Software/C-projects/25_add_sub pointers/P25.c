#include<stdio.h>
void Add_subtract(int ptr1,int ptr2,int *r1,int *r2);
int main()
{
	int x,y,result1,result2;
	printf("Enter two numbers:\n");
	scanf("%d %d",&x,&y);
	Add_subtract(x,y,&result1,&result2);
	printf("Add=%d\n",result1);
	printf("Subtract=%d\n",result2);
	
	
}
void Add_subtract(int ptr1,int ptr2,int *r1,int *r2)
{
	*r1=ptr1+ptr2;
	*r2=ptr1-ptr2;
}