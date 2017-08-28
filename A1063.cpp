#include <cstdio>
#include <set>
#include <vector>
using namespace std;
const int maxn = 10010;
int main()
{
	int n, num, id;
	scanf("%d", &n);
	vector<int> vec[51];
	for(int i = 1; i <= n; i++){
		scanf("%d", &num);
		for(int j = 0; j < num; j++){
			scanf("%d", &id);
			vec[i].push_back(id);
		}
	}
	
	int m;
	scanf("%d", &m);
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		int lena = vec[a].size();
		int lenb =vec[b].size();
		
	}
	return 0;
}


//方法二
#include <cstdio>
#include <set>
using namespace std;
const int N = 51;
set<int> st[N];
void compare(int x, int y){ //比较集合set[x]与集合set[y]
	int totalNum = st[y].size(), sameNum = 0;
	for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++){
		if(st[y].find(*it) != st[y].end())
			sameNum++;
		else 
			totalNum++;
	}
	printf("%.1f%\n", sameNum * 100.0 / totalNum);
}

int main()
{
	int n, k, q, v, st1, st2;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &v);
			st[i].insert(v);
		}
	}
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		scanf("%d%d", &st1, &st2);
		compare(st1, st2);
	}
	return 0;
}
















