#include "BinaryTree.h"

BTree * BT_CreateTree()
{
	BTree* Tree = (BTree*)malloc(sizeof(BTree));
	Tree->count = 0;
	Tree->root = NULL;
	return Tree;
}

void AddNode(BTree* tree, ElementType data)
{
	BTNode* newNode = BT_CreateNode(data);
	BTNode* prev;
	BTNode* node = tree->root;
	if (tree->root == NULL) {
		tree->root = newNode;
	}
	else {
		while (node != NULL) {
			if (node->Data > data) {
				prev = node;
				node = node->left;
				if (node == NULL)
					prev->left = newNode;
			}
			else {
				prev = node;
				node = node->right;
				if (node == NULL)
					prev->right = newNode;
			}
		}
		
	}
	tree->count++;
}

BTNode * BT_CreateNode(ElementType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->Data = data;
	newNode->right = newNode->left= NULL;
	return newNode;
}

void BT_DestroyTree(BTNode * root)
{
	if (root == NULL)
		return;

	BT_DestroyTree(root->left);
	BT_DestroyTree(root->right);
	
	free(root);
}

void PreorderPrint(BTNode * root)
{
	if (root == NULL) {
		return;
	}
	printf("%d ", root->Data);
	PreorderPrint(root->left);
	PreorderPrint(root->right);
}

void InorderPrint(BTNode * root)
{
	if (root == NULL) {
		return;
	}
	PreorderPrint(root->left);
	printf("%d ", root->Data);
	PreorderPrint(root->right);
}

void PostorderPrint(BTNode * root)
{
	if (root == NULL) {
		return;
	}
	PreorderPrint(root->left);
	PreorderPrint(root->right);
	printf("%d ", root->Data);
}

void BT_DFS(BTNode * root)
{

	if (root == NULL) {
		return;
	}
	printf("%d ", root->Data);
	
}
