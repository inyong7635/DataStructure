#include "Selection_sort.h"

void selection_sort(int *p, int count)
{
	int tmp;
	for (int i = 0;i<count-1;i++) {
		for (int j = i+1;j<count;j++) {
			if (p[i] > p[j]) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}
