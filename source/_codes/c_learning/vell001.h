#include <stdio.h>
#include <time.h>

//获取n个0～n的随机数
int* GetRandomNum(int n) {
	srand( (unsigned)time( NULL ) ); 
	int* a = (int*)malloc(n * sizeof(int));
	int i = 0;
	for(i=0; i<n; i++) {
		a[i] = rand() % n;
	}
	return a;
}

int* GetOrderedNum(int n) {
	int* a = (int*)malloc(n * sizeof(int));
	int i = 0;
	for(i=0; i<n; i++) {
		a[i] = i;
	}
	return a;
}

// 打印数组
void PrintList(int* a, int n){
	int i = 0;
	for(i=0; i<n; i++){
		printf("%d  ", a[i]);
	}
	printf("\n");
}