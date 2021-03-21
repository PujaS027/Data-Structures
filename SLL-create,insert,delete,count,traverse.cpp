#include<stdio.h>     //standard library functions
#include<stdlib.h>

typedef struct node{	//declaring node using structure
	int data;
	struct node *next;
}node;

node *head=NULL;	//global variable


node *createNode()	//node creation
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}


void insertAtEnd()	//insertion of node at end of linked list
{
	node *temp=createNode();
	printf("\nENTER DATA :");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else{
		node *ref=head;
		while(ref->next!=NULL)
			ref=ref->next;
		ref->next=temp;
	}
	printf("Data entered Successful at end!!\n");
}


void insertAtBeg()		//insertion of node at beginning of list
{
	node *temp=createNode();
	printf("\nENTER DATA : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->next=head;
	head=temp;
	printf("Data entered Successful at beg!!\n");
}


void insertAtAny()  //insert at any position of list
{
	node *temp=createNode();
	printf("\nENTER DATA : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	int pos,count=1;
	printf("Enter the position required-");
	scanf("%d",&pos);
	node *t=head,*prev;
	if(pos<=0 ||( pos>count && head==NULL))
	{
		printf("\n\t INVALID!! ");
	}
	else if(pos==1)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		while(t!=NULL && count<pos)
		{
			prev=t;
			t=t->next;
			count++;
		}
		if(pos>count)
			printf("\n\t INVALID!! ");
		else 
		{
			prev->next=temp;
			temp->next=t;
		}
	}
	printf("Data entered Successful at position given!");
	
}


void traverse()		//traversing linked list
{
	node *ref=head;
	printf("\n NODES IN LIST-");
	while(ref!=NULL)
	{
		printf("\t%d",ref->data);
		ref=ref->next;
	}
}


void countLen()		//counting no of nodes in list
{
	node *ref=head;
	int count=0;
	while(ref!=NULL)
	{
		count++;
		ref=ref->next;
	}
	printf("\n\nSIZE OF LIST IS %d\n",count);
}


void deleteFromEnd() 	//deletion of node from end
{
	node *t=head,*del;
	if(head->next==NULL)
	{
		del=head;
		head=NULL;
		printf("\nLAST BLOCK DELETION SUCCESSFUL !");
	}
	else
	{
		while(t->next->next!=NULL)
			t=t->next;
		del=t->next;
		t->next=NULL;
		printf("\nLAST BLOCK DELETION SUCCESSFUL !");
	}
	free(del);
}

void deleteFromBeg()	//deletion from beg
{
	node *t=head,*del;
	if(head==NULL)
		printf("\nLIST IS EMPTY !");
	else if(head->next==NULL)
	{
		del=head;
		head=NULL;
		printf("\nONLY BLOCK DELETED !");
	}
	else
	{
		del=head;
		head=head->next;
		printf("\nFIRST BLOCK DELETED !");
	}
	free(del);
}

void delAtAny()   //deletion at any position
{
	int pos,count=1;
	printf("Enter the position required-");
	scanf("%d",&pos);
	node *t=head,*prev,*temp;
	if(pos<=0 ||( pos>count && head==NULL))
	{
		printf("\n\t INVALID!! ");
	}
	else if(pos==1&& head!=NULL)
	{
		head=temp;
		head=head->next;
		free(temp);
	}
	else
	{
		while(t->next!=NULL && count<pos)
		{
			prev=t;
			t=t->next;
			count++;
		}
		if(pos>count)
			printf("\n\t INVALID!! ");
		else 
		{
			prev->next=t->next;
			temp=t;
			free(temp);
		}
	}	
}



int main()		//main function to call functions
{
	insertAtEnd();
	insertAtEnd();
	insertAtBeg();
	insertAtBeg();
	insertAtAny();

	traverse();
	countLen();
	
	deleteFromEnd();
	traverse();
	countLen();
	
	deleteFromBeg();
	traverse();
	countLen();
	
	delAtAny();
	traverse();
	countLen();
}
