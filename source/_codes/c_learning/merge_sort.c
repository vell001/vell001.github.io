#include "vell001.h"

#define NUM 20

// 合并a1,a2数组
void Merge(int* a1, int n1, int* a2, int n2) {
	int i, j, k;
	int* cup = (int*) malloc((n1+n2) * sizeof(int));
	// 按先放小数再放大数原则归并
	for(i=0, j=0, k=0; i<n1 && j<n2; k++) {
		if(a1[i] > a2[j]) {
			cup[k] = a2[j];
			j++;
		} else {
			cup[k] = a1[i];
			i++;
		}
	}
	// 将可能剩下的数直接放到结尾
	while(i<n1) cup[k++] = a1[i++];
	while(j<n2) cup[k++] = a2[j++];
	// 把归并好的cup数组全部复制给a1
	for(i=0; i<n1+n2; i++) a1[i] = cup[i];
	// 释放cup
	free(cup);
}

void MergeSort(int*a, int n) {
	if(n > 1){
		// 二分a数组
		int n1 = n / 2, n2 = n - n1;
		int* a1 = a, a2 = a + n1;
		
		MergeSort(a1, n1); // 递归排好左边
		MergeSort(a2, n2); // 递归排好右边
		Merge(a1, n1, a2, n2); // 归并两边
	}
}

void main() {
	int* a = GetRandomNum(NUM);
	PrintList(a, NUM);
	MergeSort(a, NUM);
	PrintList(a, NUM);
}
