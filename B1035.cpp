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
		while(j > 0 && b[j] < b[j-1]){
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
	if(i < n-1){
		while(b[i] < b[i+1] && b < n-2){
			i++;
			if(i == n-1)
				return true;
		}
		i++;
	}
	
	return false
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
	else if(Merge(a, b, n))
	{
		printf("Insertion sort\n");
	}
	return 0;
}


//方法二
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 111;
int origin[N], tempOri[N], changed[N];
int n;
bool isSame(int A[], int B[]){
	for(int i = 0; i < n; i++){
		if(A[i] != B[i])
			return false;
	}
}

bool showArray(int A[])
{
	for(int i = 0; i < n; i++){
		printf("%d", A[i]);
		if(i < n-1)
			printf(" ");
	}
	printf("\n");
}

bool insertSort()
{
	bool flag = false;
	for(int i = 1; i < n; i++){
		if( i != 1 && isSame(tempOri, changed)){
			flag = true;
		}
	}
}

int main()
{
	
}

















