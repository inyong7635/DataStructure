#include"Binary_search.h"
#include"Bubble_sort.h"
#include<string.h>

typedef struct {
	char name[10];
	int height, weight;
}Person;

int int_cmp(const int* a, const int* b) {
	if (*a < *b) {
		return -1;
	}
	else if (*a>*b) {
		return 1;
	}
	else {
		return 0;
	}
}

int p_cmp(const Person* a, const Person* b) {
	return strcmp(a->name, b->name);
}

int main() {
	int i, nx, ky;
	int* x;
	int* p;

	ky = 2;
	printf("��� ���� : ");
	scanf_s("%d", &nx, sizeof(int));
	x = calloc(nx, sizeof(int));

	printf("ã�� Ű : ");
	scanf_s("%d", &ky, sizeof(int));

	for (int i = 0; i < nx; i++) {
		x[i] = i;
	}

	p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	if (p == NULL) {
		puts("�˻��� �����߽��ϴ�.");
	}
	else {
		printf("%d�� x[%d]�� �ֽ��ϴ�.\n",ky, (int)(p-x));
	}
	free(x);

	Person e[] = {
		{"�迵��", 172, 79},
		{"������", 122, 79},
		{"���μ�", 132, 79},
		{"������", 142, 79},
		{"������", 112, 79},
		{"������", 170, 79}
	};
	nx = sizeof(e) / sizeof(Person);
	Person *p1 = NULL;
	Person temp;
	printf("�̸��� �Է��ϼ��� : ");
	scanf_s("%s", temp.name, 10);
	printf("%s\n", temp.name);
	p1 = bsearch(&temp.name, e, nx, sizeof(Person), (int(*)(const void*, const void*))p_cmp);

	if (p1 == NULL) {
		puts("�˻��� �����߽��ϴ�.");
	}
	else {
		printf("%d\n", (int)(p1 - e));
	}
}