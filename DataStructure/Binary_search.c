#include "Binary_search.h"

int binary_search(int * p, int count, int key)
{
	int low = 0;
	int high = count - 1;
	int mid;
	do {
		mid = (low + high) / 2;
		if (p[mid] == key) {
			return mid;
		}
		else if (p[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	} while (low<=high);
	
	return -1;
}
