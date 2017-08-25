#include <cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	double a[100010] = {0};  //不能用float 而是要用double
	for(int i = 0; i < n; i++){
		scanf("%lf", &a[i]);
	}
	double sum = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i-1]*(n + 1 - i)*i;
	}
	printf("%.2f\n",sum);
	return 0;
}