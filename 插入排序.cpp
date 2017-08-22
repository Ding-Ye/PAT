int A[maxn], n;
void insertSort(){
	for(int i = 2; i <= n; i++){
		int temp = A[i];
		int j = i;
		while(j > 1 && temp < A[j - 1]){
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
	}
}

int A[maxn], n;
void insertSort(){
	for(int i = 2; i <n; i++){
		int temp = A[i];
		int j = i;
		while(j > 1 && temp < A[j-1]){
			A[j] = A[j-1];
			j--
		}
		A[j] = temp;
	}
}









