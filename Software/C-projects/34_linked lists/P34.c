#include<stdio.h>
#include"../STD_TYPES/STD_TYPES.h"
#include<stdlib.h>
typedef struct Node
{
	u8 data;
	struct Node*next;
}node_t;

int main()
{
	node_t*head=(node_t*)malloc(sizeof(node_t));
	node_t*ptr=head;
	node_t*first=(node_t*)malloc(sizeof(node_t));
	node_t*second=(node_t*)malloc(sizeof(node_t));
	head->data=20;
	first->data=30;
	second->data=40;
	
	head->next=first;
	first->next=second;
	second->next=NULL;
	
	while (ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}

}