#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
} Node;
void display(struct Node* head) {
	struct Node* temp = head;
	printf("**DISPLAY DATA**\n");
	while(temp != NULL) {
		printf("Your data is - %d\n", temp->data);
		temp = temp->next;
	}
}
struct Node* deletionEnd(struct Node* head){
	Node *temp1,*temp2;
	temp1=head;
	while(temp1!=NULL)
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	temp2->next=NULL;
	free(temp1);
	return head;
}
struct Node* createNode(struct Node *head)
{
	struct Node *newNode;
	int data;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	printf("Enter Your Data");
	scanf("%d",&data);
	newNode->data=data;
	newNode->next=NULL;
	if(head==NULL)
	{
		head=newNode;
	}
}
struct Node* insertEnd(struct Node *head){
	struct Node* temp=head;
	struct Node* newNode;
	while(temp!=NULL)
	{		
		temp=temp->next;
	}
	newNode=createNode(head);
	temp->next=newNode;
}
struct Node* atFront(struct Node *head)
{
	struct Node *newNode;
	newNode=createNode(head);
	newNode->next=head;
	head=newNode;	
	return head;
}

void main(){
	struct Node *head;
	head=NULL;
	head=createNode(head);
	head=insertEnd(head);
	head=insertEnd(head);
	head=insertEnd(head);
	head=insertEnd(head);
//	head=atfront(head);
	display(head);
	head=deletionEnd(head);
	display(head);
}
