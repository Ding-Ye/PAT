#include <iostream>
#include <algorithm>
#include "Heap.h"

using namespace std;

template<typename T>
void heapSort1(T arr[], int n){
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for(int i = 0; i < n; i++){
		maxheap.insert(arr[i]);
	}
	
	for(int i  = n-1; i >= 0; i++){
		arr[i] = maxheap.extractMax();
	}
}


int main(){
	
	return 0;
}