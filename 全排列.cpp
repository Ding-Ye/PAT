#include <cstdio>
const int maxn = 11;
int n, p[maxn], hashTable[maxn] = {false};
void generateP(int index){
	if(index == n+1){
		for(int i = 1; i <= n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}
	for(int x = 1; x <= n; x++){
		if(hashTable[x] == false){
			P[index] = x;
			hashTable = true;
			generateP(index + 1);
		}
	}
}