#include"LinkedList.h"

Node* LL_CreateNode(ElementType data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = data;
	newNode->Next = NULL;
	return newNode;
}
void LL_DestroyNode(Node *node) {
	free(node);
}
void InsertTail(Node** head, Node* newNode) {
	Node* tail = *head;

	if (*head == NULL) {
		*head = newNode;
	}
	else {
		while (tail->Next != NULL) {
			tail = tail->Next;
		}
		tail->Next = newNode;
	}

}
void InsertAfter(Node* current, Node* newNode) {
	newNode->Next = current->Next;
	current->Next = newNode;
}
void Insert(Node** head, Node* newNode) {
	if (*head == NULL) {
		*head = newNode;
	}
	else {
		newNode->Next = *head;
		*head = newNode;
	}
}
void LL_RemoveNode(Node** head, Node* removed) {
	Node* current = *head;

	if (removed == *head) {
		*head = removed->Next;
	}
	else {
		while (current != NULL && current != removed) {
			current = current->Next;
		}
		if (current != NULL) {
			current->Next = removed->Next;
		}
	}
	LL_DestroyNode(removed);
}
Node* GetNode(Node* head, int location) {
	Node* current = head;
	while (current != NULL && --location >=0) {
		current = current->Next;
	}
	return current;
}
int GetNodeCount(Node* head) {
	int count = 0;
	Node* current = head;
	while (current != NULL) {
		current = current->Next;
		count++;
	}

	return count;
}