#include<stdio.h>
int main()
{
	//Inserting array by user
	int Arr[10],i,j,temp;
	for (i=0;i<10;i++)
	{
		printf("Enter %d number:",i+1);
		scanf("%d",&Arr[i]);
		printf("\n");
	}
	//bubble sorting the array
	for(i=0;i<9;i++)
	{
		for (j=0;j<(9-i);j++)
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
	for (i=0;i<10;i++)
	{
		printf("sorted array:%d\n",Arr[i]);
	}
	//searching for an element
	int index= -1,middle,start=0,end=9;
	int search;
	printf("insert your search value:");
	scanf("%d",&search);
	while (start<=end)
	{
		middle=(start+end)/2;
		if (search==Arr[middle])
		{
			index=middle;
			break;
		}
		else if (search<Arr[middle])
		{
			end=middle-1;
		}
		else
		{
			start=middle+1;
		}	
	}
	if (index==-1)
	{
		printf("Value of search is not found in the array");
	}
	else
	{
		printf("The index of your search value=%d",index);
	}
}
