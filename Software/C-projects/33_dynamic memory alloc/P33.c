#include<stdio.h>
#include"../STD_TYPES/STD_TYPES.h"
#include<stdlib.h>
int main(void)
{
	u8 i,j,temp,size;
	u8 *ptr;
	printf("enter no. of elements in array: ");
	scanf("%d",&size);
	ptr= (u8*)malloc(size*(sizeof(u8)));
	
	for (i=0;i<size;i++)
	{
		printf("Enter %d element: ",i+1);
		scanf("%d",&ptr[i]);
	}
	
	for (i=0;i<size-1;i++)
	{
		for (j=0;j<size-i-1;j++)
		{
			if (ptr[j]>ptr[j+1])
			{
				temp=ptr[j];
				ptr[j]=ptr[j+1];
				ptr[j+1]=temp;
			}
		}
	}
	
	for (i=0;i<size;i++)
	{
		printf("%d\n",ptr[i]);
	}
}
