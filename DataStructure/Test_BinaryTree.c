#include"BinaryTree.h"
#include<stdlib.h>
#include<stdio.h>

int main() {

	BTree *tree = BT_CreateTree();
	AddNode(tree, 10);
	
	AddNode(tree, 2);
	
	AddNode(tree, 11);
	AddNode(tree, 1);
	AddNode(tree, 3);

	PreorderPrint(tree->root);
}