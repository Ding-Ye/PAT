#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1111;
vector<int>G[N];//�ڽӱ�
bool vis[N];

int currentPoint; //��ǰ��Ҫɾ���Ķ�����

//dfs��v����������v���ڵ���ͨ��
void dfs(int v){
	if(v == currentPoint)//���������Ѿ�ɾ������vʱ������
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
		scanf("%d %d", &a, &b);//����ͼ�Ĺ���
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




