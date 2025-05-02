#include <stdio.h>
#include <stdlib.h>

// Define the Binary Search Tree (BST) node structure
typedef struct BST {
    int data;
    struct BST *left, *right;
} bst;

// Define the Queue structure
typedef struct Queue {
    bst** array;
    int front, rear, size, capacity;
} Queue;

// Function to create a new BST node
bst* createNode(int data) {
    bst* newNode = (bst*)malloc(sizeof(bst));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (bst**)malloc(queue->capacity * sizeof(bst*));
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Add an element to the queue
void enqueue(Queue* queue, bst* item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
}

// Remove an element from the queue
bst* dequeue(Queue* queue) {
    if (isEmpty(queue))
        return NULL;
    bst* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return item;
}

// Level order traversal function
void levelOrderTraversal(bst* root) {
    if (root == NULL)
        return;

    Queue* queue = createQueue(100); // Create a queue with capacity 100
    enqueue(queue, root);
    enqueue(queue, NULL); // NULL marks the end of a level

    while (!isEmpty(queue)) {
        bst* temp = dequeue(queue);

        if (temp == NULL) {
            // Level completed
            printf("\n");
            if (!isEmpty(queue)) {
                enqueue(queue, NULL); // Add marker for the next level
            }
        } else {
            printf("%d ", temp->data);
            if (temp->left) {
                enqueue(queue, temp->left);
            }
            if (temp->right) {
                enqueue(queue, temp->right);
            }
        }
    }

    free(queue->array);
    free(queue);
}

// Function to insert a node into the BST
bst* insert(bst* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Main function
int main() {
    bst* root = NULL;
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 12);
    printf("Level Order Traversal:\n");
    levelOrderTraversal(root);

    return 0;
}

