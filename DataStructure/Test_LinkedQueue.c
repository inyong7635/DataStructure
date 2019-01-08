#include"LinkedQueue.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
	Node* node;

	LinkedQueue* queue;
	CreateQueue(&queue);

	Enqueue(queue, CreateNode(1));
	Enqueue(queue, CreateNode(2));
	Enqueue(queue, CreateNode(3));
	Enqueue(queue, CreateNode(4));
	Enqueue(queue, CreateNode(5));

	printf("Queue Size : %d\n", queue->count);

	while (isEmpty(queue) == 0) {
		printf("Dequeue : %d , Size: %d\n", Dequeue(queue), queue->count);

	}

	DestroyQueue(queue);
}