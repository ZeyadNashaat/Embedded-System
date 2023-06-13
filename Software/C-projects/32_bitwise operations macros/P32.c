#include<stdio.h>
#include"../STD_TYPES/STD_TYPES.h"
#include"../BIT_MATH/BIT_MATH.h"
int main()
{
	u8 x=2;
	SET_BIT(x,0);//x=3
	printf("%d\n",x);
	CLR_BIT(x,1);//x=1
	printf("%d\n",x);
	TOGGLE_BIT(x,2);//x=5
	printf("%d\n",x);
	u8 y=GET_BIT(x,1);
	printf("%d",y);//y=0
}