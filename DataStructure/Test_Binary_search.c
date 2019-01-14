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
	printf("요소 개수 : ");
	scanf_s("%d", &nx, sizeof(int));
	x = calloc(nx, sizeof(int));

	printf("찾는 키 : ");
	scanf_s("%d", &ky, sizeof(int));

	for (int i = 0; i < nx; i++) {
		x[i] = i;
	}

	p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	if (p == NULL) {
		puts("검색에 실패했습니다.");
	}
	else {
		printf("%d는 x[%d]에 있습니다.\n",ky, (int)(p-x));
	}
	free(x);

	Person e[] = {
		{"김영준", 172, 79},
		{"나병준", 122, 79},
		{"다인수", 132, 79},
		{"라이주", 142, 79},
		{"마이주", 112, 79},
		{"사지우", 170, 79}
	};
	nx = sizeof(e) / sizeof(Person);
	Person *p1 = NULL;
	Person temp;
	printf("이름을 입력하세요 : ");
	scanf_s("%s", temp.name, 10);
	printf("%s\n", temp.name);
	p1 = bsearch(&temp.name, e, nx, sizeof(Person), (int(*)(const void*, const void*))p_cmp);

	if (p1 == NULL) {
		puts("검색에 실패했습니다.");
	}
	else {
		printf("%d\n", (int)(p1 - e));
	}
}