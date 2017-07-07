#include "vell001.h"

// 使用与符号交换
void swap_1(int* a, int* b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

// 使用加减运算符交换
void swap_2(int* a, int* b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void main(){
	int a=1, b=2;
	printf("(a=%d, b=%d)\n", a, b);
	swap_1(&a, &b);
	printf("(a=%d, b=%d)\n", a, b);
	swap_2(&a, &b);
	printf("(a=%d, b=%d)\n", a, b);
}
