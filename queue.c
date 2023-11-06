#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

void initialize(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

bool isFull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(Queue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->items[++queue->rear] = data;
    }
}

int dequeue(Queue *queue) {
    int data = -1;
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        data = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front++;
        }
    }
    return data;
}

int front(Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->items[queue->front];
    } else {
        printf("Queue is empty. No front element.\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(&queue));

    printf("Dequeued elements: ");
    while (!isEmpty(&queue)) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    return 0;
}
