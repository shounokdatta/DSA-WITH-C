#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}node;
node* append(int data,node* head){
	node *newNode,*temp;
	newNode=(node*)malloc(sizeof(node));
	newNode->data=data;
	newNode->next=NULL;
	if(head==NULL){
		head=newNode;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
		
	}
	return head;
	
}

node* display(node* temp){
printf("\nPrinting the List--\n");
while(temp!=NULL)
{
//	printf("a");
    printf("%d ",temp->data);
    temp=temp->next;
}

return temp;
}
node* bubbleSort(node* head) {
    if (head == NULL) 
	return NULL;

    int swapped;
    node* ptr;
    node* end = NULL;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != end) {
            if (ptr->data > ptr->next->data) {
                int tempData = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = tempData;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        end = ptr;  
    } while (swapped);
}

int main(){
	node* head1;
	node* head;
	head1=NULL;
	int size,i;
	int arr[]={8, 9, 7, 2 ,5,10,12,50};
	size=(sizeof(arr)/sizeof(arr[0]));
	for(i=0;i<size;i++){
	 head1=append(arr[i],head1);
	}	
	display(head1);
	bubbleSort(head1);
	display(head1);
	
}
