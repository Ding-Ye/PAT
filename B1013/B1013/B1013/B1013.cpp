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