#include "ChainHash.h"
#include "Member.h"
#include<stdio.h>
#include<stdlib.h>

static int hash(int key, int size) {
	return key % size;
}

static void SetNode(Node *n, const Member *x, const Node *next) {
	n->data = *x;
	n->next = next;
}

int Initialize(ChainHash * h, int size)
{
	h->size = size;
	h->table = calloc(size, sizeof(ChainHash *));
	for (int i = 0;i<size;i++) {
		h->table[i] = NULL;
	}
	return 0;
}

Node * Search(const ChainHash * h, const Member * x)
{
	int key = hash(x->no, h->size);
	Node *p = h->table[key];

	while (p != NULL) {
		if (p->data.no == x->no)
			return p;
		p = p->next;
	}
	return NULL;
}

int Add(ChainHash * h, const Member * x)
{
	Node *tmp;
	int key = hash(x->no, h->size);
	Node *p = h->table[key];
	while (p != NULL) {
		if (p->data.no == x->no)
			return 1;
		p = p->next;
	}

	tmp = calloc(1, sizeof(Node));
	SetNode(tmp,x,h->table[key]);
	h->table[key] = tmp;
	return 0;
}

int Remove(ChainHash * h, const Member * x)
{
	int key = hash(x->no, h->size);
	Node *p = h->table[key];
	Node **pp = &h->table[key];
	while (p != NULL) {
		if (p->data.no==x->no) {
			*pp = p->next;
			free(p);
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}
	return 1;
}

void Dump(ChainHash * h)
{
	
}

void Clear(ChainHash * h)
{
	int i;
	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];
		while (p != NULL) {
			Node *next = p->next;
			free(p);
			p = next;
		}
		h->table[i] = NULL;
	}
}

void Terminate(ChainHash * h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
}
