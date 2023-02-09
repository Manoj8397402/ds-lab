#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void main()
{
	int choice=0;
	while(choice!=7)
	{	
		printf("\n********Main Maenu********\n");
		printf("\n Choose one option from the following...\n");
		printf("\n1.insert in begining\n2.insert at last\n3.delete from begining\n4.delete from last\n5.search for an element\n6.show\n7.exit\n");
		printf("\n Enter your choice?\n");
		scanf("\n%d",&choice);
		switch(choice)
		{
			case 1:
			beginsert();
			break;
			case 2:
			lastinsert();
			break;
			case 3:
			begin_delete();
			break;
			case4:
			last_delete();
			break;
			case 5:
			search();
			break;
			case 6:
			display();
			break;
			case 7:
			exit(0);
			break;
			default:
			printf("Please enter valid choice..");
		}
	}
}
void beginsert()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if (ptr==NULL)
	{
		printf("\nOVERFLOW");
	}
	else
	{
		printf("\n enter the node data?");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
		}
		else
		{
			
			temp=ptr;
			while(temp->next!=head)
			temp=temp->next;
			ptr->next=head;
			temp->next=ptr;
			head=ptr;
		}
		printf("\n node inserted\n");
	}
}
void lastinsert()
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node*)malloc(sizeof(struct node));
	if (ptr==NULL)
	{
		printf("\n OVERFLOW\n");
	}
	else
	{
		printf("\n enter data?");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			head=ptr;
			ptr->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=head;
		}
		printf("\n node inserted\n");
	}
}
void begin_delete()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("\n UNDERFLOW");
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
		printf("\n node deleted\n");
	}
	else
	{ 	ptr=head;
		while(ptr->next!=head)
		ptr=ptr->next;
		free(head);
		head=ptr->next;
		printf("\n node deleted\n");
	}
}
void last_delete()
{
	struct node *ptr,*preptr;
	if(head=NULL)
	{
		printf("\n UNDERFLOW");
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
		printf("\n node deleted\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=head)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
		printf("\n node deleted\n");
	}
	
}
void search()
{
	struct node *ptr;
	int item,i=0,flag=1;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n Empty List\n");
	}
	else
	{
		printf("\n enter item which you want to search?\n");
		scanf("%d",&item);
		if(head->data==item)
		{
			printf("item found at location %d",i+1);
			flag=0;
		}
		else
		{
			while(ptr->next!=head)
			{
				if(ptr->data==item)
				{
					printf("item found at location %d",i+1);
					flag=0;
					break;
				}
				else
				{
				flag=1;
				}
				i++;
				ptr=ptr->next;
			}
		}
		if(flag!=0)
		{
			printf("item not found\n");
		}
	}
}
void display()
{
	struct node *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\n nothing to print");
	}
	else
	{
		printf("\n printing values...\n");
		while(ptr->next=head)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n",ptr ->data);
	}
}
	
		


