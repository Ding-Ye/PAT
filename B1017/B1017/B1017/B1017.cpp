#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int main()
{
	int n;
	int a[maxn];
	int sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int c, b;
		int dis = 0;
		scanf("%d %d", &b, &c);
		if(b == c)
			dis = 0;
		else if(b < c){
			for(int i = b-1; i < c-1; i++){
				dis += a[i];
			}
		}
		else{
				for(int i = c-1; i < b-1; i++){
					dis += a[i];
				}
		}

		dis = min(dis, sum-dis);
	    printf("%d\n", dis);
	}
	
	return 0;
}
