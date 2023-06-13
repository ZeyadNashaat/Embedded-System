#include<stdio.h>
int main()
{
//Inserting array by user
	int n;
	printf("Enter no. of elements in array:");
	scanf("%d",&n);
	int Arr[n],i,j,temp;
	for (i=0;i<n;i++)
	{
		printf("Enter %d number:",i+1);
		scanf("%d",&Arr[i]);
		printf("\n");
	}
//bubble sorting the array
	for(i=0;i<(n-1);i++)
	{
		for (j=0;j<((n-1)-i);j++)
		{
			if (Arr[j]>Arr[j+1])
			{
				//swap
				temp=Arr[j];
				Arr[j]=Arr[j+1];
				Arr[j+1]=temp;
			}
		}
	}
//printing bubble sorted array
	printf("sorted array=[");
	for (i=0;i<n;i++)
	{
		if (i==(n-1))
		{
			printf("%d",Arr[i]);
		}
		else
		{
			printf("%d,",Arr[i]);
		}
	}
	printf("]\n");
//removing duplicated elements
	j=0;
	for (i=0;i<(n-1);i++)
	{
		if (Arr[i]!=Arr[i+1])
		{
			Arr[j]=Arr[i];
			j++;
		}
	}
	Arr[j]=Arr[n-1];
//printing unique array
	printf("unique array=[");
	for(i=0;i<=j;i++)
	{
		if (i==j)
		{
			printf("%d",Arr[i]);
		}
		else
		{
			printf("%d,",Arr[i]);
		}
	}
	printf("]");
	
}

