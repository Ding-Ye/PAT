1只能用于有序序列
#include <iostream>

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target){//迭代    迭代与递归的异同
	//在arr[l, r]之中查找target
	int l = 0, r = n-1;
	while(l <= r){
		int mid = l + (r-l)/2;
		if(arr[mid] == target)
			return mid;
		if(target < arr[mid]){
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return -1;
}

//用递归的方式写二分查找法
template<typename T>
int __binarySearch2(T arr[], int l, int r, target){
	if(l < r)//递归边界
		return -1;
		
	int mid = l + (r-l)/2;
	
	if(arr[mid] == target)
		return mid;
	else if(arr[mid] < target){
		return __binarySearch2(arr, mid+1, r, target);
	}
	else
		return __binarySearch2(arr, l, mid-1, target);
}

template<typename T>
int binarySearch2(T arr[], int n, T target){
	return __binarySearch2(arr, 0, n-1, target);
}


int main(){
	
}


































