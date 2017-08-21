#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	int a[100010];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int cout = 0;
	long long mei = p*a[0];
	for(int i = 0; i < n; i++){
		if(a[i] <= mei){
			cout++;
		}
	}
	printf("%d", cout);
	return 0;
}