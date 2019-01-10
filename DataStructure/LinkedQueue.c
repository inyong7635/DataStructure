#include "LinkedQueue.h"


void CreateQueue(LinkedQueue ** Queue)
{
	*Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->count = 0;
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
}

void DestroyQueue(LinkedQueue * Queue)
{
	
	while (isEmpty(Queue) == 0) {
		Dequeue(Queue);
	}

	free(Queue);
}

Node * CreateNode(ElementData data)
{
	Node *newnode = (Node*)malloc(sizeof(Node));
	newnode->Data = data;
	newnode->Next = NULL;
	return newnode;
}

void DestroyNode(Node * node)
{
	free(node);
}

void Enqueue(LinkedQueue * Queue, Node * newnode)
{
	if (Queue->Front == NULL) {
		Queue->Front = newnode;
		Queue->Rear = newnode;
		Queue->count++;
	}
	else {
		Queue->Rear->Next = newnode;
		Queue->Rear = newnode;
		Queue->count++;
	}
	
}

ElementData Dequeue(LinkedQueue * Queue)
{
	ElementData ret = Queue->Front->Data;
	Node* node = Queue->Front;
	if (Queue->Front->Next == NULL) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else {
		Queue->Front = Queue->Front->Next;
	}
	DestroyNode(node);
	Queue->count--;
	return ret;
}

int isEmpty(LinkedQueue * Queue)
{
	return Queue->Front == NULL;
}
