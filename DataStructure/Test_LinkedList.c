#include"LinkedList.h"

int main() {
	int i = 0;
	int count = 0;
	Node* list = NULL;
	Node* current = NULL;
	Node* newNode = NULL;

	for (int i = 0;i<5;i++) {
		newNode = LL_CreateNode(i);
		InsertTail(&list, newNode);
	}

	newNode = LL_CreateNode(-1);
	Insert(&list, newNode);
	newNode = LL_CreateNode(-2);
	Insert(&list, newNode);

	count = GetNodeCount(list);

	for (int i = 0;i<count;i++) {
		current = GetNode(list,i);
		printf("%d번째 노드 : [%d]\n", i+1, current->Data);
	}
	printf("\n");
	current = GetNode(list,2);
	newNode = LL_CreateNode(2000);

	InsertAfter(current, newNode);

	count = GetNodeCount(list);
	for (int i = 0; i < count; i++) {
		current = GetNode(list, i);
		printf("%d번째 노드 : [%d]\n", i + 1, current->Data);
	}

	printf("\n");
	for (int i = 0; i < count; i++) {
		current = GetNode(list, 0);

		if (current != NULL) {
			printf("%d번째 노드 : [%d]를 제거합니다.\n",i+1, current->Data);
			LL_RemoveNode(&list,current);
		}
	}
}
