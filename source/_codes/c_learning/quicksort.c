#include "vell001.h"

#define NUM 20

// 对a的[low, high]区间分成两个区，返回分界点
int Partition(int* a, int low, int high){
	int key = a[low]; // 划分的关键点
	while(low < high){
		while(low < high && a[high] >= key) --high; // 找到比关键点小的节点
		a[low] = a[high]; // 把小节点放到左边
		while(low < high && a[low] <= key) ++low; // 找到比关键点大的节点
		a[high] = a[low]; // 把小节点放到右边
	}
	a[low] = key; // 最后把关键点放到分界点
	return low;
}

// 对a的[low, high]区间进行快速排序
int* QSort(int* a, int low, int high){
	if(low < high){
		int p = Partition(a, low, high);
		QSort(a, low, p-1); // 递归的对左分区快排
		QSort(a, p+1, high); // 递归的对右分区快排
	}
}

int* QuickSort(int* a, int n) {
	return QSort(a, 0, n-1);
}

void main() {
	int* a = GetRandomNum(NUM);
	PrintList(a, NUM);
	QuickSort(a, NUM);
	PrintList(a, NUM);
}