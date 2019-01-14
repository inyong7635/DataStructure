#include "Bubble_sort.h"

void bubble_sort(int *p, int count){
	int tmp;
	for (int i = count-1;i>0;i--) {
		for (int j = 0;j<i;j++) {
			if (p[j] > p[j+1]) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}
