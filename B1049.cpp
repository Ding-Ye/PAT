#include <cstdio>
int MAXN = 100010;
int main()
{
	int n;
	scanf("%d", &n);
	float a[MAXN];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum = a[i]*((n-i)*(i+1));
	}
	printf("%.2f\n",sum);
	return 0;
}