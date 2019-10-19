#include <stdio.h>
#include <stdlib.h>
#define EMPTY -1

// Stores one node of the linked list.
struct node {
    int data;
    struct node* next;
};

// Stores our queue.
struct queue {
    struct node* front;
    struct node* back;
};

void init(struct queue* qPtr);
int enqueue(struct queue* qPtr, int val);
int dequeue(struct queue* qPtr);
int empty(struct queue* qPtr);
int front(struct queue* qPtr);

int main() {
    
    
    struct queue* MyQueuePtr = (struct queue*)malloc(sizeof(struct queue));
    init(MyQueuePtr);
    
    // Enqueue some items.
    enqueue(MyQueuePtr, 3);
    enqueue(MyQueuePtr, 7);
    enqueue(MyQueuePtr, 4);
    
    // Try one dequeue.
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    
    // Enqueue one more item, then try several dequeues and one front.
    enqueue(MyQueuePtr, 2);
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("At Front of Queue Now: %d\n", front(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    
    
    printf("Is empty: %d\n", empty(MyQueuePtr));
    
    
    enqueue(MyQueuePtr, 5);
    enqueue(MyQueuePtr, 9);
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    printf("Dequeue %d\n", dequeue(MyQueuePtr));
    
    system("PAUSE");
    return 0;
}


void init(struct queue* qPtr) {
    
    // Just set both pointers to NULL!
    qPtr->front = NULL;
    qPtr->back = NULL;
    
}



int enqueue(struct queue* qPtr, int val) {
    struct node* temp;
    temp = (struct node*) malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = val;
        temp->next = NULL;
        if(qPtr->back != NULL){
            qPtr->back->next = temp;
        }
        qPtr->back = temp;
        if(qPtr->front == NULL){
            qPtr->front = temp;
        }
        return 1;
    }
    else
        return 0;
}



// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: If the queue pointed to by qPtr is non-empty, then the value
int dequeue(struct queue* qPtr) {
    struct node* tmp;
    int retval;
    if(qPtr->front == NULL){
        return EMPTY;
    }
    retval = qPtr->front->data;
    tmp = qPtr->front;
    qPtr->front = qPtr->front->next;
    if(qPtr->front == NULL){
        qPtr->back = NULL;
    }
    free(tmp);
    return retval;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: returns true iff the queue pointed to by pPtr is empty.
int empty(struct queue* qPtr) {
    return qPtr->front == NULL;
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: if the queue pointed to by qPtr is non-empty, the value

int front(struct queue* qPtr) {
    if(qPtr->front != NULL){
        return qPtr->front->data;
    }
    else{
        return EMPTY;
    }
}

