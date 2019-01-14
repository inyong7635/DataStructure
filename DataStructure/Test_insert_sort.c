#include"Insert_sort.h"

int main() {

	int p[5] = { 6,5,9,1, 2 };
	insert_sort(p, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d ", p[i]);
	}
}