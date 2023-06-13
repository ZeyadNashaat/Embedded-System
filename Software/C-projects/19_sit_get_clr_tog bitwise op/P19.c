#include<stdio.h>
int set_bit(int num,int bitnum);
int clear_bit(int num, int bitnum);
int toggle_bit(int num, int bitnum);
int get_bit(int num, int bitnum);
int main()
{
	int x,y,new;
	char z;
	printf("Enter the number:\n");
	scanf("%d",&x);
	printf("Enter the bit number:\n");
	scanf("%d",&y);
	printf("Enter s for set, c for clear, t for toggle, or g for get bit:\n");
	scanf(" %c",&z);
	switch (z)
	{
		case 's':
		new= set_bit(x,y);
		break;
		case 'c':
		new=clear_bit(x,y);
		break;
		case 't':
		new= toggle_bit(x,y);
		break;
		case 'g':
		new= get_bit(x,y);
		break;
		default:
		printf("Enter s,c,or t");
	}
	printf("%d",new);
	
	
}
//-------------------------------------------
int set_bit(int num, int bitnum)
{
	int result;
	result= num | (1<<bitnum);
	return result;
}
//--------------------------------------------
int clear_bit(int num, int bitnum)
{
	int result;
	result= num & (~(1<<bitnum));
	return result;
}
//---------------------------------------------
int toggle_bit(int num, int bitnum)
{
	int result;
	result= num ^ (1<<bitnum);
	return result;
}
//---------------------------------------------
int get_bit(int num, int bitnum)
{
	int result;
	result= (num &(1<<bitnum))>>bitnum;//or (num>>bitnum)&1
	return result;
}
