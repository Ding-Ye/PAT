#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void downAdjust(int low, int high){//堆维护
	int i = 1, j = i*2;
	while(j <= high){
		if(j + 1 <= high && b[j] < b[j + 1]){
			j = j + 1;
		}
		if(b[i] < b[j]){
			swap(b[i], b[j]);
			i = j;
			j = i * 2;
		}
		else{
			break;
		}
	}
}

int main(){
	int n, p = 2;
	scanf("%d", &n);
	a.resize(n + 1);
	b.resize(n + 1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	
	while(p <= n && b[p - 1] <= b[p])//前几个是增序
		p ++;
	
	int index = p;
	while(p <= n && a[p] == b[p])
		p ++;
	
	if(p == n + 1){
		printf("Insertion Sort\n");
		sort(b.begin() + 1, b.begin() + index + 1);//同过前面的判断是否是插入排序
		
		printf("%d", b[1]);
		for(int i = 2; i <= n; i++)
			printf(" %d", b[i]);
		
	}
	else{
		printf("Heap Sort\n");
		p = n;
		while(p >= 2 && b[p] >= b[p-1])
			p--;
		swap(b[1], b[p]);
		downAdjust(1, p - 1);
		printf("%d", b[1]);
		for(int i = 2; i <= n; i++){
			printf(" %d", b[i]);
		}
	}
	return 0	
}





















