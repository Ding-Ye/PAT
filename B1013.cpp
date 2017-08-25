//题目理解出错
#include <cstdio>
#include <cmath>

bool isPrime(int n){
	if(n <= 1)
		return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i = 2; i <= sqr; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	int count = 0;
	for(int i = m ; i <=n; i++){
		if(count <= 9 && isPrime(i)){
			printf("%d ", i);
			count++;
		}
		else if(count == 10 && isPrime(i)){
			printf("%d\n", i);
			count = 0;
		}
	}
	
	return 0;
}

//
#include <stdio.h>
#include <math.h>
const int maxn = 1000001;
bool isPrime(int n){
	if(n <= 1)
		return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i = 2; i <= sqr; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int prime[maxn], num = 0;
bool p[maxn] = {0};
void Find_Prime(int n){
	for(int i = 1; i< maxn; i++){
		if(isPrime(i) == true){
			prime[num++] = i;
			p[i] = true;
			if(num >= n)
				break;
		}
	}
}

int main()
{
	int m, n, count = 0;
	scanf("%d%d", &m, &n);
	Find_Prime(n);
	for(int i = m; i <= n; i++){
		printf("%d", prime[i - 1]);
		count ++;
		if(count % 10 != 0 && i < n)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}

//方法二
#include <stdio.h>
const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};
void Find_Prime(int n){
	for(int i = 2; i < maxn; i++){
		if(p[i] == false){
			prime[num++] = i;
			if(num >= n)
				break;
			for(int j = i + i; j < maxn; j +=i ){
				p[j] = true;
			}
		}
	}
}

int main()
{
	int m, n, count = 0;
	scanf("%d%d", &m, &n);
	Find_Prime(n);
	for(int i = m; i <= n; i++){
		printf("%d", prime[i - 1]);
		count++;
		if(count % 10 != 0 && i < n)
			printf(" ");
		else
			printf("\n");
	}
	
	return 0;
}





















