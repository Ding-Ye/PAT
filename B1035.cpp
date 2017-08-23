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
int n; //做成全局变量
bool isSame(int A[], int B[]){
	for(int i = 0; i < n; i++){
		if(A[i] != B[i])
			return false;
	}
	return true;
}
void showArray(int A[])//判断A和B数组是不是相同
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
		int temp = tempOri[i], j = i;
		while(j > 0 && tempOri[j-1] > temp){
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true){
			return true;
		}
	}
	return false;
}

void mergeSort()
{
	bool flag = false;
	for(int step = 2; step/2 <= n; step *= 2){
		if(step != 2 && isSame(tempOri, changed)){
			flag = true;
		}
		for(int i = 0; i < n; i += step){
			sort(tempOri + i, tempOri + min(i+step, n));
		}
		if(flag == true){
			showArray(tempOri);
			return;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &changed[i]);
	}
	if(insertSort()){
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else{
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++){
			tempOri[i] = origin[i];
		}
		mergeSort();
	}
	return 0;
}