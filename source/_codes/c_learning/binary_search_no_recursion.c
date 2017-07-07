#include "vell001.h"

#define NUM 100

// no recursion binary search
int BinarySearch(int* a, int low, int high, int key){
	// middle index
	int mid;

	while(high >= low){
		mid = (low + high) / 2;
		if(a[mid] > key) high = mid - 1;
		else if(a[mid] < key) low = mid + 1;
		else return mid;
	}
	return -1;
}

void main(){
	int* a = GetOrderedNum(NUM);
	PrintList(a, NUM);
	printf("%d", BinarySearch(a, 0, NUM-1, 99));
}