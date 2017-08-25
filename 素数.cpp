1.然后判定n是不是素数
2.如何在较短的时间内得到1~ 1n内的素数表
//方法一
#include <stdio.h>
#include <math.h>
bool isPrime(int n){
	if(n <= 1)
		return false;
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 2; i <= sqr; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int prime[101], pNum = 0;
bool p[101] = {0};
void Find_Prime(){
	for(int i = 1; i < 101; i++){
		if(isPrime(i) == true){
			prime[pNum++] = i;
			p[i] = true;
		}
	}
}

int main()
{
	Find_Prime();
	for(int i = 0; i < pNum; i++){
		printf("%d", prime[i]);
	}
	return 0;
}


//方法二 刷选法
#include <stdio.h>
const int maxn = 101;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};
void Find_Prime(){
	for(int i = 2; i < maxn; i++){
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
	Find_Prime();
	for(int i = 0; i < pNum; i++){
		printf("%d", prime[i]);
	}
	return 0;
}














