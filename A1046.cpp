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



//应该使用累加函数
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int dis[MAXN], A[MAXN];
int main()
{
	int sum = 0, query, n, left, right;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &A[i]);
		sum += A[i];
		dis[i] = sum; //预处理dis数组 这一步很关键不然就会超时
	}
	scanf("%d", &query);
	for(int i = 0; i < query; i++){
		scanf("%d %d", &left, &right);
		if(left > right) 
			swap(left, right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp));
	}
	return 0;
}


















