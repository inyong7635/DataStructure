#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct tagBTNode{
	struct tagBTNode *left, *right;
	ElementType Data;
}BTNode;

typedef struct tagBTree {
	BTNode* root;
	int count;
}BTree;

BTree* BT_CreateTree();
void AddNode(BTree* tree, ElementType data);

BTNode* BT_CreateNode(ElementType data);
void BT_DestroyTree(BTNode* root);

void PreorderPrint(BTNode* root);
void InorderPrint(BTNode* root);
void PostorderPrint(BTNode* root);

void BT_DFS(BTree* tree);