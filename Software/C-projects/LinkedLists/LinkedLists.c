#include<stdio.h>
#include"../../C-projects/STD_TYPES/STD_TYPES.h"
#include<stdlib.h>

/* struct declaration*/
typedef struct node
{
	u32 value;
	struct node* next;
}node_t;

/*Add node function to end declaration*/
void ADDNODETOEND(node_t* Head, u32 data);
/*Add node to middle function declaration*/
void ADDNODETOMIDDLE(node_t* Head, u32 data, u8 index);
/*print list declaration*/
void PrintList(node_t*Head);

int main()
{
	u32 input=0,index,Value,first=0;
	node_t* Head= (node_t*)malloc(sizeof(node_t));
	Head->next=NULL;
	while(input!=3)
	{
		printf("Enter: (0)to add a node to end\n(1) to add node to middle\n(2) to print the nodes \n(3) to exit");
		scanf("%d",& input);
		
		switch (input)
		{
			case(0):
			printf("Enter value of node: \n");
			scanf("%d",&Value);
			if (first==0)
			{
				Head->value=Value;
				first=1;
			}
			else
			{
				ADDNODETOEND(Head,Value);
			}
			printf("Node is successfully added\n");
			break;
			case(1):
			printf("Enter index and value respectivly: \n");
			scanf("%d%d",&index,&Value);
			if (first==0)
			{
				Head->value=Value;
				first=1;
			}
			else
			{
				ADDNODETOMIDDLE(Head,Value,index);
			}
			printf("Node is successfully added\n");
			break;
			case(2):
			PrintList(Head);
			break;
		}
	}
}

/*ADDNODETOEND implementation*/
void ADDNODETOEND(node_t* Head, u32 data)
{
	node_t*ptr=Head;
	//creating new node
	node_t* new= (node_t*)malloc(sizeof(node_t));
	//assign value to new node
	new->value=data;
	//assign pointer of last new node to null
	new->next=NULL;
	//loop on linked lists until finding last node before adding the new
	while (ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=new;
}

/*ADDNODETOMIDDLE implementation*/
void ADDNODETOMIDDLE(node_t* Head, u32 data, u8 index)
{
	u8 i;
	node_t*ptr=Head;
	/*create a new node*/
	node_t*new=(node_t*) malloc(sizeof(node_t));
	/*Assign value to new node*/
	new->value=data;
	//allocating new node in given index
	for (i=0;i<index-1;i++)
	{
		ptr=ptr->next;
	}
	new->next=ptr->next;
	ptr->next=new;
}
/*PrintList implementation*/
void PrintList(node_t*Head)
{
	node_t* ptr=Head;
	while (ptr!=NULL)
	{
		printf("%d\n",ptr->value);
		ptr=ptr->next;
	}
}