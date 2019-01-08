#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int ElementData;

typedef struct tagNode {
	ElementData Data;
	struct tagNode* Next;
}Node;

typedef struct tagLinkedQueue {
	Node* Front;
	Node* Rear;
	int count;
}LinkedQueue;

void CreateQueue(LinkedQueue** Queue);
void DestroyQueue(LinkedQueue* Queue);

Node* CreateNode(ElementData data);
void DestroyNode(Node* node);

void Enqueue(LinkedQueue* Queue, Node* newnode);
ElementData Dequeue(LinkedQueue* Queue);

int isEmpty(LinkedQueue* Queue);