1.递归实现
2.只需要反复将当前区间[left, right]分为两半，对两个子区间[left, mid]与[mid+1，right]分别进行递归
const int maxn = 100;
void merge(int A[], int L1, int R1, int L2, int R2){
	int i = L1;
	int j = L2;
	int temp[maxn], index = 0;
	while(i <= R1 && j <= R2){
		if(A[i] <= A[j]){
			temp[index++] = A[i++];
		}
		else{
			temp[index++] = A[j++];
		}
	}
	
	while(i <= R1)
		temp[index++] = A[i++];
	while(j <= R2)
		temp[index++] = A[j++];
	for(i = 0; i < index; i++){
		A[L1 + i] = temp;
	}
}

2.非递归实现
void mergeSort(int A[]){
	for(int step = 2; step/2 <=n; step *= 2){
		for(int i = 1; i <=n; i+=step){
			int mid = i + step/2 - 1;
			if(mid + 1 <= n){
				merge(A, i, mid, mid+1, min(i+step-1, n));
			}
		}
	}
}

























