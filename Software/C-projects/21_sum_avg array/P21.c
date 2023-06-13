#include<stdio.h>
int main()
{
	int i;
	float avg, Arr[10],sum=0.0;
	for (i=0;i<10;i++)
	{
		printf("Enter %d number:",i+1);
		scanf("%f",&Arr[i]);
		printf("\n");
		sum=sum+Arr[i];
	}
	avg=sum/10;
	printf("Sum=%0.2f\n",sum);
	printf("Average=%0.2f",avg);
}