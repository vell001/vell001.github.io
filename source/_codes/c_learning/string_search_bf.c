#include <stdio.h>

// search str2 from str1, return start index if found, return -1 if not found
int BruteForceSearch(char* str1, int n, char* str2, int m){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<m && str1[i+j]==str2[j]; j++);
		if(j>=m) return i;
	}
	if(i>=n) return -1;
}

void main(){
	char* str1 = "vells01vels001vell001vall002";
	char* str2 = "vell001";
	printf("%d", BruteForceSearch(str1,28,str2,7));
}