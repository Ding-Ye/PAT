1.用邻接表来存储树
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10;

vector<int> G[N];
int leaf[N] = {0};
int max_h = 1;

void DFS(int index, int h){
	max_h = max(h, max_h);
	if(G[index].size() == 0){
		leaf[h] ++;
		return;
	}
	for(int i = 0; i < G[index].size(); i++){
		DFS(G[index][i], h+1);
	}
}

int main(){
	int n, m, parent, child, k;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &parent, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			G[parent].push_back(child);
		}
	}
	DFS(1, 1);
	printf("%d", leaf[1]);
	for(int i = 2; i <= max_h; i++){
		printf(" %d", leaf[i]);
	}
	return 0;
}

//DFS方法二
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];
int book[100], maxdepth = -1;
void dfs(int index, int depth) {
    if(v[index].size() == 0) {
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&node, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);
        }
    }
    dfs(1, 0);
    printf("%d", book[0]);
    for(int i = 1; i <= maxdepth; i++)
        printf(" %d", book[i]);
    return 0;
}



//BFS版本
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int N = 105;

 vector<int>G[N];
 int h[N] = {0};
 int leaf[N] = {0};
 int max_h = 0;
 
 void BFS(){
	 queue<int>Q;
	 Q.push(1);
	 while(!Q.empty()){
		 int id = Q.freont();
		 Q.pop();
		 max_h = max(max_h, h[id]);
		 if(G[id].size() == 0){
			 leaf[h[id]] ++;
		 }
		 for(int i = 0; i < G[id].size(); i++){
			 h[G[id][i]] = h[id] + 1;
			 Q.push(G[id][i]);
		 }
	 }
 }

 int main(){
	 int n, m;
	 scanf("%d %d", &n, &m);
	 for(int i = 0; i < m; i++){
		 int parent, k, child;
		 scanf("%d %d", &parent, &k);
		 for(int j = 0; j < k; j++){
			 scanf("%d", &child);
			 G[parent].push_back(child);
		 }
	 }
	 h[1] = 1;
	 BFS();
	 for(int i = 1; i <= max_h; i++){
		 if(i == 1)
			 printf("%d", leaf[i]);
		 else
			 printf(" %d", leaf[i]);
	 }
	 return 0;
 }












