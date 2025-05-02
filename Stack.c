#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void display(){
	int i;
	for(i=top;i>=0;i--)
	{
		printf("data is- %d\n",stack[i]);
	}
}
int peek(){
	if(top==-1)
	printf("Stack is empty");
	 else
	 {
	 	printf("%d",stack[top]);
	 	return;
	 }		
}

int pop()
{
	if(top==-1)
	printf("Stack is underflow");
	else
	{
		printf("your data is %d",stack[top]);
		top--;
	}
}
void push(){
//	printf("*");
	int data;
	scanf("%d",&data);
	if(top==(N-1))
	{
		printf("The satack is overflow");
		return;
	}
	else
	{
		top++;
		stack[top]=data;
	}
}
void main(){
	int ch,i;
	i=0;
	while(1!=-1)
	{
		printf("1 to push ||2 to display ||3 to peek ||4 to pop|| 0 to Exit\n");
		scanf("%d",&ch);
	switch(ch)
	{
	case 1: 
			push();
			break;
	case 2: 
			display();
			break;
	case 3: 
			peek();
			break;
	case 4:	
			pop();
			break;
	case 0:
		 return;
	default: 
			printf("Invaild choice");
			break;
	}
}
}

