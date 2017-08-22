//题目理解出错
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


//方法2
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

int binarySerach(int i , long long x){
	if(a[n - 1] <= x)
		return n;
	int l = i +1; 
	int r = n - 1; 
	int mid;
	while(l < r){
		mid = (1+r)/2;
		if(a[mid] <= x){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}
	return l;
}

int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int ans = 1;
	for(int i = 0; i < n; i++){
		int j = binarySerach(i, (long long)a[i]*p);
		ans = max(ans, j-i);
	}
	printf("%d\n", ans);
	return 0;
}

//方法三
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];
int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int ans = 1;
	for(int i = 0; i < n; i++){
		int j = upper_bound(a+i+1, a+n, (long long)a[i]*p) - a;
		ans = max(ans, j-i);
	}
	printf("%d\n", ans);
	return 0;
}

//方法三
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];
int main()
{
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int ans = 1;
	int i = 0;
	int j = n-1;
    while(i < j){
		if(a[j]/a[i] > p){
			j--
		}
		ans = max(ans, j-i);
	}
	
	printf("%d\n", ans);
	return 0;
}















































