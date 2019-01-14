#include "Insert_sort.h"

void insert_sort(int * p, int count)
{
	int tmp;
	for (int i = 1;i<count;i++) {
		for (int j = i;j>0;j--) {
			if (p[j] < p[j-1]) {
				tmp = p[j-1];
				p[j - 1] = p[j];
				p[j] = tmp;
			}
			else {
				break;
			}
		}
	}
}
