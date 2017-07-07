#include <stdio.h>
#define MOD 100;

int ELFHash(char* key){
	unsigned long h=0;
	while(*key){
		h=(h<<4)+*key++;
		unsigned long g=h&0Xf0000000L;
		if(g)
			h^=g>>24;
		h&=~g;
	}
	return h%MOD;
}

int main(){
	printf("%d", ELFHash("hello"));
}