#include <stdio.h>
#include "STD_TYPES.h"
struct employees
{
	u16 salary;
	u16 bonus;
	u16 ded;
};
int main(void)
{
	struct employees Ahmed,Walid,Amr;
	int sum;
	printf("Please enter salary of Ahmed");
	scanf("%d",&Ahmed.salary);
	printf("Please enter bonus of Ahmed");
	scanf("%d",&Ahmed.bonus);
	printf("Please enter deductions of Ahmed");
	scanf("%d",&Ahmed.ded);
	
	printf("Please enter salary of Walid");
	scanf("%d",&Walid.salary);
	printf("Please enter bonus of Walid");
	scanf("%d",&Walid.bonus);
	printf("Please enter deductions of Walid");
	scanf("%d",&Walid.ded);
	
	printf("Please enter salary of Amr");
	scanf("%d",&Amr.salary);
	printf("Please enter bonus of Amr");
	scanf("%d",&Amr.bonus);
	printf("Please enter deductions of Amr");
	scanf("%d",&Amr.ded);
	sum=Ahmed.salary+Walid.salary+Amr.salary;
	sum=sum+Ahmed.bonus+Walid.bonus+Amr.bonus;
	sum=sum-(Ahmed.ded+Walid.ded+Amr.ded);
	printf("Total=%d",sum);

}