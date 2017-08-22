const int maxn = 100;
void merge(int A[], int L1, int R1, int L2, int R2){
	int i = L1, j = L2;
	int temp[maxn], index = 0;
	while(i <= R1 && j <= R2){
		if(A[i] <= A[j]){
			temp[index++] = A[i++];
		}
		else{
			temp[index++] = A[j++];
		}
	}
	while(i <= R1) temp[index++] = A[i++];
	while(j <= R2) temp[index++] = A[j++];
	for(i = 0; i < index; i++){
		A[L1 + i] = temp[i];
	}
}