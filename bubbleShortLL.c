#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
void printLine()
{	int i;
	for (i=0;i<50;i++)
	{
		printf("-");
	}
	printf("\n");
}
int length(struct Node* head){
	int i = 0; 
	struct Node* temp = head;
	while(temp!=NULL) {
		i++;
		temp = temp->next;
	}
	return i;
}
struct Node* bubbleSort(Node* head)
{
	Node *end,*ptr1,*ptr2,*x,*temp;
	if(head==NULL||head->next==NULL)
	{
		printf("List is Empty\n");
//		return NULL;
	}
	for(end=NULL;end!=head;end=ptr1)
	{
		for(x=ptr1=head;ptr1->next!=end;ptr1=ptr1->next)
		{
			ptr2=ptr1->next;
			if(ptr1->data>ptr2->data)
			{
				ptr1->next=ptr2->next;
				ptr2->next=ptr1;
				if(ptr1!=head)
					x->next=ptr2;
				else 
					head=ptr2;
		
				temp=ptr1;
				ptr1=ptr2;
				ptr2=temp;
			}
			x=ptr1;
		}
	}
	return head;
}
void display(struct Node* head) {
	struct Node* temp = head;
	printf("**DISPLAY DATA**\n");
	while(temp != NULL) {
		printf("Your data is - %d\n", temp->data);
		temp = temp->next;
	}
}
struct Node* lastNode(struct Node* head) {
	struct Node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	return temp;
}
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
struct Node* append(struct Node* head,int data) {
	struct Node *newNode, *temp;
	newNode = createNode(data);
	if(head == NULL) {
		head = newNode;
		return head;
	}
	temp = lastNode(head);
	temp->next = newNode;
	return head;
}
int main() {
	int arr[]={1000,5,4,6,3,7,9,1,2,100},n,i;
	n=sizeof(arr)/sizeof(arr[0]);
	struct Node* head = NULL;
//	bubblesort(head);
//	head = append(head);
	for(i=0;i<n;i++)
	{
		head=append(head,arr[i]);
//		break;
	}
	printLine();
	printf("\nBefore Sorting:\n");
	display(head);
	printLine();
	head =bubbleSort(head);
	printf("\nAfter Sorting:\n");
	display(head);
	printLine();
	return 0;
}

