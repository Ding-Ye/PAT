//第一输入格式的问题
#include <cstdio>
int main()
{
	int n;
	scanf("%d ", &n);
	int num[110] = {0};
	int a[110] = {0};
	for(int i = 0; i < n; i++){

		scanf("%d", &a[i]); 
		
		if(num[a[i]] != 0)
			break;
		
		while(k != 1){
			if( (k%2==0) && (k/2 >= 1) && (k/2 <=100) ){
				k = k/2;
				num[k]--;
			}
			else if( ((3*k+1)/2 >= 1) && ((3*k+1)/2 <=100) ){
				k = (3*k+1)/2;
				num[k]--;
			}
		}
	}
	
	for(int i = 109; i>0; i--){
		if(num[i] == 1){
			printf("%d ", i);
		}
	}
	return 0;
}

//方法二
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
	return a > b;
}
int main()
{
	int n, m, a[110];
	scanf("%d", &n);
	bool HashTable[10000] = {0};
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		m = a[i];
		
		if(HashTable[m] == true)
			break;
		
		while(m != 1 ){
			if(m % 2 == 1)
				m = (3*m + 1)/2;
			else m = m/2;
			HashTable[m] = true;
		}
	}
	
	int count = 0;
	for(int i = 0; i < n; i++){
		if(HashTable[a[i]] == false){
			count ++;
		}
	}
	
	sort(a, a+n, cmp);
	for(int i = 0; i < n; i++){
		if(HashTable[a[i]] == false){
			printf("%d", a[i]);
			count --;
			if(count > 0)
				printf(" ");
		}
	}
	return 0;
}

























