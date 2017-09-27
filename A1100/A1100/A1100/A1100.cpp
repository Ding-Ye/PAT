#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1111;
vector<int>G[N];//邻接表
bool vis[N];

int currentPoint; //当前需要删除的顶点编号

//dfs（v）遍历顶点v所在的连通块
void dfs(int v){
	if(v == currentPoint)//当遍历到已经删除顶点v时，返回
		return;
	
	vis[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(vis[G[v][i]] == false){
			dfs(G[v][i]);
		}
	}
}

int n, m, k;
int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);//无向图的构建
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for(int query = 0; query < k; query++){
		scanf("%d", &currentPoint);
		memset(vis, false, sizeof(vis));
		int block = 0;
		for(int i = 1; i <= n; i++){
			if(i != currentPoint && vis[i] == false){
				dfs(i);
				block++;
			}
		}
		printf("%d\n", block - 1);
	}
	return 0;
}




