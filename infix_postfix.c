#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>                   //for (isalnum()) 
char stack[20];    //global declaration
int top =-1;            //global declaration
void push(char x)            //push function here, inserts value in stack and increments by one
{
	stack[++top]=x;
}
char pop()                      //function to remove an element and decreases by one
{
	if (top==-1)
		return -1;
	else
	{
		return stack[top--];
	}
}

int priority(char x)                         //precedence according to operator 
{
	if(x =='(')
		return 0;
	if(x=='+'||x=='-')
		return 1;
	if(x=='*'||x=='/')
		return 2;
}
int main()                  //main function converts infix to postfix expression
{
	char exp[20];
	char *e, x;
	printf("Enter the expression: \n");
	scanf("%s", exp);
	e = exp;
	while (*e!='\0')
	{
		if(isalnum(*e))
			printf("%c", *e);
		else if (*e=='(')
			push (*e);
		else if (*e==')')
		{
			while((x=pop())!='(')
				printf("%c", x);
		}
		else
		{
			while (priority(stack[top])>=priority(*e))
				printf("%c",pop());
			push(*e);
		}
		e++;	
	}
	while (top!=-1)
	{
		printf("%c",pop());
	}
}
