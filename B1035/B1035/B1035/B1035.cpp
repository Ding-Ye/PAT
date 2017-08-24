#include <cstdio>
bool Insertion(int a[], int b[], int n){//怎么传数组
	int i = n-1;
	while(a[i] == b[i]){
		i--;
	}
	int j = i+1;//标记下一个插入排序点
	while(b[i] >= b[i-1] && i>=1){
		i--;
	}
	
	if(i == 0){
		int temp = b[j];
		while(j > 0 && temp < b[j-1]){
			b[j] = b[j-1];
			j--;
		}
		b[j] = temp;
		return true;
	}
	else
		return false;
	
}

bool Merge (int a[], int b[], int n){
	int i = 0;
	while(i < n-1){
		while(b[i] < b[i+1] && i < n-1){
			i++;
			if(i == n-1)
				return true;
		}
		i++;
	}
	
	return false;
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[110];
	int b[110];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	
	if(Insertion(a, b, n)){
		printf("Insertion sort\n");

		for(int i = 0; i < n; i++){
			printf("%d ", b[i]);
		}

	}

	 if(Merge(a, b, n))
	{
		printf("Merge Sort\n");
	}
	return 0;
}