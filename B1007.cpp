#include <cstdio>
const int maxn = 100010;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
void Find_Prime(int n){
	for(int i = 2; i < n; i++){
		if(p[i] == false){
			prime[pNum++] = i;
			for(int j = i+i; j < maxn; j += i){
				p[j] = true;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	Find_Prime(n);
	int count = 0;
	for(int i =0; i < pNum-1; i++){
		if(prime[i+1] - prime[i] == 2)
			count++;
	}
	printf("%d\n", count);
	return 0;
}

//方法二
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
	int n, count = 0;
	scanf("%d", &n);
	for(int i = 3; i + 2 <= n; i += 2){
		if(isPrime(i) == true && isPrime(i+2) == true){
			count++;
		}
	}
	printf("%d\n", count);
	return 0;
}