#include <cstdio>
#include <vector>
using namespace std;
const int N = 1111;
vector<int> G[N]; //邻接表

int father[N];  
bool vis[N];
int findFather(int x){ //查找x所在的集合
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	//路径压缩
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Uion(int a , int b){//合并a和b所在的集合
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

//初始化father数组与hashtable数组
void init(){
	for(int i = 1; i < N; i++){
		father[i] = i;
		vis[i] = false;
	}
}

int n, m, k;
int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int currentPoint; //当前需要删除的顶点编号
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			int u = i; v = G[i][j]
			if(u == currentPoint || v == currentPoint)
				continue;
			Uion(u, v);
		}
	}
	
	int block = 0;
	for(int i = 1; i <= n; i++){
		if(i == currentPoint)
			continue;
		int fa_i = findFather(i);
		if(vis[fa_i] == false){
			block ++;
			vis[fa_i] = true;
		}
		printf("%d\n", block - 1);
	}
	
	return 0;
}