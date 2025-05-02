#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}node;
struct Node* push(int data,node *top){
	struct Node* newNode;
	newNode=(node*)malloc(sizeof(node));
	newNode->data=data;
	newNode->next=top;
	top=newNode;
	return top;
}
void display(node* top){
	node *temp;
	temp=top;
	if(top==NULL)
		printf("Stack is Underflow");
	else
	{
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
 struct Node* pop(node* top){
 	node* temp=top;
 	if(top==NULL)
 	printf("UnderFlow");
 	top=temp->next;
 	free(temp);
 	return top;
 }
 node* peek(node* top)
 {
 	if(top==NULL)
 	printf("stack is empty");
 	printf("%-10d",top->data);
 }
void main(){
	node *top=NULL;
	top=push(3,top);
	top=push(6,top);
	top=push(7,top);
	peek(top);
	display(top);
	top=pop(top);
	top=pop(top);
	printf("after pop\n");
	display(top);
}

