#include <stdio.h>
#include <stdlib.h>

#define MagicFactor  1.5

/* Notice that the queue is nothing but a "List" that adds from the last position and adds
removes from  the front position
i.e, First In First Out (FIFO)
*/
// Define the queue struct
typedef struct {
    int* items;     // Pointer to the array of items in the queue
    int front;      // Index of the front of the queue
    int rear;       // Index of the rear of the queue
    int size;       // Current size of the queue
    int capacity;   // Current capacity of the queue
} Queue;

// Function to create a new queue with a given initial capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(sizeof(int) * capacity);
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if (queue->size == queue->capacity) {
        // If the queue is full, resize it to double its current capacity
        queue->capacity *= MagicFactor;
        queue->items = (int*)realloc(queue->items, sizeof(int) * queue->capacity);
    }
    queue->rear++;
    queue->items[queue->rear] = item;
    queue->size++;
}

// Function to remove an item from the queue
int dequeue(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    queue->size--;
    return item;
}

// Function to peek at the front item of the queue
int peek(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}