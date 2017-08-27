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
		
	}
	return 0;
}















