#include<stdio.h>
#define N 5
int queue[N];
int front =-1;
int rear =-1;
int dequeue(){
	if(front==-1 && rear==-1)
	printf("queue is under flow");
	else if(front==rear)
	{
		printf("your dlt data is %d\n",queue[front]);
		front=rear=-1;
	}
	else{
		printf("your dlt data is %d\n",queue[front]);
		front++;
	}
}
void display(){
	int i;
	for(i=front;i<=rear;i++)
	{
		printf("data is %d\n",queue[i]);
	}
}
int enqueue(int data)
{
	if(rear==(N-1))
	{
		printf("queue is full\n");
	}
	else if(front==-1 && rear==-1)
	{
		queue[rear+1]=data;
		front++;
		rear++;
	}
	else{
		rear++;
		queue[rear]=data;
	}
	
}
void main(){
	int i;
	int arr[]={5,6,7,18,9};
	for(i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{
		enqueue(arr[i]);
	}
	display();
	dequeue();
	dequeue();
	display();

}
