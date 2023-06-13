#include<stdio.h>
int main()
{
	int Arr[10],i;
	for (i=0;i<10;i++)
	{
		printf("Enter %d number:",i+1);
		scanf("%d",&Arr[i]);
		printf("\n");
	}
	printf("the values in reversed order:\n");
	for (i=9;i>=0;i--)
	{
		printf("%d\n",Arr[i]);
	}
}