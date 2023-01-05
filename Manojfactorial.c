#include<stdio.h>
int fact(int);
int main()
{
	int n,f;
	printf("enter number\n");
	scanf("%d",&n);
	f=fact(n);
	printf("factorial is %d",f);
}
int fact(int n)
{
	int result;
	if (n==0)return 0;
	else
	if(n==1)return 1;
	else
	{
	result=n*fact(n-1);
	return result;
	}
}
