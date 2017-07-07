#include "vell001.h"

#define NUM 100

// 在a的[low, high]区间内找到ley的位置并返回
int BinarySearch(int* a, int low, int high, int key){
	if(low > high) return -1;
	// 算出中间位置
	int mid = (low + high) / 2;

	if(key > a[mid]){
		return BinarySearch(a, mid + 1, high, key);
	} else if(key < a[mid]){
		return BinarySearch(a, low, mid - 1, key);
	} else return mid;
}

void main(){
	int* a = GetOrderedNum(NUM);
	PrintList(a, NUM);
	printf("%d", BinarySearch(a, 0, NUM-1, 1));
}
