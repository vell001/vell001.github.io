#include "vell001.h"

#define NUM 20

int* ShellSort(int* a, int n){
	int i = 0, j = 0, d = n, cup = 0;
	for(d=n/2; d>=1; d=d/2){ // 增量d为上次增量的一半，初始增量为总长度的一半
		for(i=d; i<n; i++){ // 分出来的所有组进行插入排序
			cup = a[i];
			for(j=i-d; j>=0 && a[j]>cup; j=j-d){
				a[j+d] = a[j];
			}
			a[j+d] = cup;
		}
	}
	return a;
}

void main(){
	int* a = GetRandomNum(NUM);
	PrintList(a, NUM);
	ShellSort(a, NUM);
	PrintList(a, NUM);
}