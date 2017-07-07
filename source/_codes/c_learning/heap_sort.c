#include "vell001.h"

#define NUM 15

// 保证i位置为堆中最大的节点
// a:待调整堆数组，n:数组长度, i:待调整元素位置
int* HeapAdjust(int* a, int n, int i){
	int child, cup;
	// i: 父节点位置，child: 子节点位置（左:2*i+1,右:2*i+2）
	for(cup = a[i], child=2*i+1; child<n; i=child, child=2*i+1){
		// 如果右节点大于左节点child指向右节点
		if(child < n-1 && a[child+1] > a[child]) child++;
		// 如果子节点大于父节点则交换，并继续查找下一个节点（把当前的子节点当成新的父节点）
		if(a[child] > cup){
			a[i] = a[child];
			a[child] = cup;
		} else
			break; //如果不大于，则退出
	}
	return a;
}

// a:待调整堆数组，n:数组长度
int* HeapSort(int* a, int n){
	int cup, i;
	// 初始化堆，即对所有的非叶子节点进行HeapAdjust
	for(i = n/2; i>=0; i--){
		HeapAdjust(a, n, i);
	}
	// 把堆顶节点（最大节点）和堆中最后一个节点交换，然后对堆中除最后一个节点外的其他节点进行HeapAdjust
	for(i = n-1; i>0; i--){
		cup = a[i];
		a[i] = a[0];
		a[0] = cup;
		HeapAdjust(a, i, 0);
	}
	return a;
}

void main(){
	int* a = GetRandomNum(NUM);
	PrintList(a, NUM);
	HeapSort(a, NUM);
	PrintList(a, NUM);
}
