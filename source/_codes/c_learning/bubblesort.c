#include "vell001.h"

#define NUM 20

int* BubbleSort(int* a, int n){
	int i = 0, j = 0, flag = 1, cup = 0;
	for(i=n-1; i>0 && flag; i--){
		flag = 0; // 设置一个标记，当顺序已经排好后不再运行
		for(j=0; j<i; j++){
			if(a[j] > a[j+1]){
				cup = a[j];
				a[j] = a[j+1];
				a[j+1] = cup;
				flag = 1;
			}
		}
	}
	return a;
}

void main(){
	int* a = GetRandomNum(NUM);
	PrintList(a, NUM);
	BubbleSort(a, NUM);
	PrintList(a, NUM);
}