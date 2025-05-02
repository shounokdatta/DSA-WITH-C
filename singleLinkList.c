#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node *head = NULL;

void adddata(int data) {
    node *n = (node*)malloc(sizeof(node));  // Correct memory allocation
    if (n == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    n->val = data;
    n->next = NULL;
    if (head == NULL) {
        head = n;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void printdata() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void deleteatthefirst(node** head) {
    if (*head == NULL) return;
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteatend(node** head) {
    if (*head == NULL) return;
    node *p = *head;
    node *q = p->next;

    if (q == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

void deleteatany(node** head, int index) {
    if (*head == NULL || index < 1) return;
    if (index == 1) {
        deleteatthefirst(head);
        return;
    }
    node *p = *head;
    node *q = p->next;
    for (int i = 1; i < index - 1 && q != NULL; i++) {
        p = p->next;
        q = q->next;
    }
    if (q == NULL) return;
    p->next = q->next;
    free(q);
}

int main() {
    adddata(5);
    adddata(3);
    adddata(9);
    adddata(55);
    printf("Original list:\n");
    printdata();
    deleteatthefirst(&head);
    printf("After deleting the first node:\n");
    printdata();
    deleteatany(&head, 1);
    printf("After deleting node at index 1:\n");
    printdata();
    deleteatend(&head);
    printf("After deleting the last node:\n");
    printdata();
    return 0;
}

