#include<stdio.h>
#include"STD_TYPES.h"
typedef struct
{
	u16 math;
	u16 language;
	u16 physics;
	u16 chemistry;
}student;
u16 main()
{
	student Arr[10];
	u16 i=0;
	for (i=0;i<10;i++)
	{			
		Arr[i].math=i*2;
		Arr[i].language=i*3;
		Arr[i].physics=i*4;
		Arr[i].chemistry=i*5;
	}
	u16 x;
	printf("Enter student ID");
	scanf("%d",&x);
	if (x<1||x>10)
	{
		printf("Enter right ID");
	}
	else
	{
		printf("Math=%d\n",Arr[x].math);
		printf("Language=%d\n",Arr[x].language);
		printf("Physics=%d\n",Arr[x].physics);
		printf("Chemistry=%d",Arr[x].chemistry);
	}
}