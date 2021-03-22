//DOUBLE LINKED LIST

#include<stdio.h>     //standard library functions
#include<stdlib.h>

typedef struct node{	//declaring node using structure
	int data;
	struct node *prev;
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
	temp->prev=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else{
		node *ref=head;
		while(ref->next!=NULL)
			ref=ref->next;
		temp->prev=ref;
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
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		head->prev=temp;
		temp->next=head;
		head=temp;
	}
	printf("Data entered Successful at beg!!\n");
}

void insertAtAny()  //insert at any position of list
{
	node *temp=createNode();
	printf("\nENTER DATA : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	int pos,count=1;
	printf("Enter the position required-");
	scanf("%d",&pos);
	
	if(pos<=0 ||( pos>count && head==NULL))
		printf("\n\t INVALID!! ");
	else if(pos==1 && head==NULL)
		head=temp;
	
	else if(pos==1)
	{
		head->prev=temp;
		temp->next=head;
		head=temp;
	}
	else
	{
		node *t=head;
		while(t->next!=NULL && count<pos)
		{
			t=t->next;
			count++;
		}
		if(pos>count)
			printf("\n\t INVALID!! ");
		else 
		{
			temp->prev=t->prev;
			temp->next=t;
			t->prev->next=temp;
			t->prev=temp;
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

void deleteFromEnd() 	//deletion of node from end
{
	if(head==NULL)
	{
		printf("\n\n NO NODE IS PRESENT IN LIST ");
		return;
	}
	node *t=head,*del;
	if(head->next==NULL)
	{
		del=head;
		head=NULL;
		printf("\n\nLAST BLOCK DELETION SUCCESSFUL !");
	}
	else
	{
		while(t->next!=NULL)
			t=t->next;
		del=t;
		t->prev->next=NULL;
	}
	printf("\n\nLAST BLOCK DELETION SUCCESSFUL !");
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
		printf("\n\nONLY BLOCK DELETED !");
	}
	else
	{
		del=head;
		head=head->next;
		head->prev=NULL;
	}	
	printf("\n\nFIRST BLOCK DELETED !");
	free(del);
}

void delAtAny()   //deletion at any position
{
	if(head==NULL)
		printf("\nLIST IS EMPTY !");
	int pos,count=1;
	printf("\n\nEnter the position required-");
	scanf("%d",&pos);
	
	node *t=head,*temp;
	if(pos<=0 ||( pos>count && head==NULL))
		printf("\n\t INVALID!! ");
	
	else if(pos==1&& head->next==NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
		printf("\n\n DATA DELETION SUCCESSFUL !");
	}
	else if(pos==1 && head!=NULL)
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		printf("\n\n DATA DELETION SUCCESSFUL !");
	}
	else
	{
		while(t->next!=NULL && count<pos)
		{
			t=t->next;
			count++;
		}
		if(pos>count)
			printf("\n\t INVALID!! ");
		else 
		{
			t->prev->next=t->next;
			if(t->next!=NULL)
				t->next->prev=t->prev;
			temp=t;
			free(temp);
			printf("\n\n DATA DELETION SUCCESSFUL !");
	
		}
	}	
}

int main()
{
	insertAtEnd();
	insertAtEnd();
	insertAtBeg();
	insertAtBeg();
	insertAtAny();
	traverse();
	
	deleteFromEnd();
	traverse();
	
	deleteFromEnd();
	traverse();
	
	deleteFromBeg();
	traverse();
	
	delAtAny();
	traverse();
	
	delAtAny();
	traverse();
	
}
