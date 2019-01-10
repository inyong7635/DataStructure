#pragma once

#include<stdio.h>
#include<stdlib.h>


typedef int ElementType;

typedef struct tageNode{
	ElementType Data;
	struct tagNode* Next;
}Node;

Node* LL_CreateNode(ElementType data);
void LL_DestroyNode(Node *node);
void InsertTail(Node** head, Node* newNode);
void InsertAfter(Node* current, Node* newNode);
void Insert(Node** head, Node* newNode);
void LL_RemoveNode(Node** head, Node* removed);
Node* GetNode(Node* head, int location);
int GetNodeCount(Node* head);