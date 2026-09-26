#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

// Initialize the queue
void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Check if queue is empty
bool isEmpty(CircularQueue *q) {
    return q->count == 0;
}

// Check if queue is full
bool isFull(CircularQueue *q) {
    return q->count == MAX_SIZE;
}

// Add element to the queue
bool enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return false;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = value;
    q->count++;
    return true;
}

// Remove element from the queue
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return value;
}

// Get front element
int getFront(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

// Get rear element
int getRear(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->rear];
}

// Display the queue
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->arr[(q->front + i) % MAX_SIZE]);
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);          // 10 20 30 40

    dequeue(&q);
    dequeue(&q);
    display(&q);          // 30 40

    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);      // Wraps around
    display(&q);          // 30 40 50 60 70

    enqueue(&q, 80);      // Queue full

    printf("Front: %d\n", getFront(&q));  // 30
    printf("Rear:  %d\n", getRear(&q));   // 70

    return 0;
}