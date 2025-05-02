#include <stdio.h> 
#include <stdlib.h> 
struct Node {
int data;
struct Node* next;
};
void push(struct Node** top, int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
if (!newNode) {
printf("Memory allocation failed\n");
return;
}
newNode->data = value;
newNode->next = *top;
*top = newNode;
printf("Pushed %d onto the stack\n", value);
}
int pop(struct Node** top) {
if (*top == NULL) {
printf("Stack underflow\n");
return -1;
}
struct Node* temp = *top;
int poppedValue = temp->data;
*top = (*top)->next;
free(temp);
return poppedValue;
}
void display(struct Node* top) {
if (top == NULL) {
printf("Stack is empty\n");
return;
}
struct Node* temp = top;
printf("Stack elements: ");
while (temp != NULL) {
19
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main() {
struct Node* top = NULL;
int choice, value;
do {
printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter the value to push: ");
scanf("%d", &value);
push(&top, value);
break;
case 2:
value = pop(&top);
if (value != -1) {
printf("Popped %d from the stack\n", value);
}
break;
case 3:
display(top);
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid choice\n");
}
} while (choice != 4);
return 0;
}
