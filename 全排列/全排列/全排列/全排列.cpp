#include <cstdio>
const int maxn = 11;
int n, P[maxn], hansTable[maxn] = {false};
void generateP(int index){
	if(index == n+1){
		for(int i = 1; i <= n; i++){
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}
	for(int x = 1; x <= n; x++){//在循环中加递归，让整体变的好麻烦
		if(hansTable[x] == false){
			P[index] = x;
			hansTable[x] = true;
			generateP(index + 1);
			hansTable[x] = false;
		}
	}
}

int main()
{
	n = 2;
	generateP(1);
	return 0;
}