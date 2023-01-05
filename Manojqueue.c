#include<stdio.h>
#include<stdlib.h>
#define size 5
void enqueue();
void dequeue();
void display();
int front=-1;
int rear=-1;
int queue[size];
int main()
{
	int choice;
	int x;
	while(1)
	{
		printf("\n1.insert\n2.delete\n3.display\n4.exit\n");
		printf("enter choice");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			case 4:exit(0);
			default:printf("invalid choice\n");
		}
	}
}
void enqueue()
{
	int x;
	printf("enter element:");
	scanf("%d",&x);
	if(front==size-1)
	{
		printf("overflow\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=x;
		printf("value is inserted\n");
	}
	else
	{
		rear++;
		queue[rear]=x;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	printf("underflow");
	else if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		printf("%d",queue[front]);
		front++;
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("underflow");
	}
	printf("printing value");
	for(i=front;i<=rear;i++)
	printf("%d\n",queue[i]);
}
