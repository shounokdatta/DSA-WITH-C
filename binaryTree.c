#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* create(){
	int data;
	struct node* newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("ENTER DATA \nFOR EXIT ENTER -1\n");
	scanf("%d",&data);
	if(data==-1){
		newNode->left=NULL;
		newNode->right=NULL;
		return 0;
	}	
	else{
		newNode->data=data;
		printf("Enter right child of %d\n",data);
		newNode->right=create();
		printf("Enter left child of %d\n",data);
		newNode->left=create();
		return newNode;
	}
}
void main(){
	struct node* root;
	root=0;
	root=create();
}
