#include <stdio.h>

// record the step number
int N = 0;

// move floor n to b from a
void move(int n, char a, char b){
	printf("%d  %d : %c->%c\n", ++N, n, a, b);
}

// move a to b by c
void hanoi(int n, char a, char b, char c){
	if(n>0){
		hanoi(n-1, a, c, b);
		move(n, a, b);
		hanoi(n-1, c, b, a);
	}
}

void main(){
	hanoi(16, 'a', 'b', 'c');
}