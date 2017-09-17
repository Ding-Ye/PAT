1.树的静态写法
#include  <cstdio>
#include <vector>
using namespace std;
const int MAXN = 110;
vector<int> Node[MAXN];
int hashTable[MAXN] = {0};
void DFS(int index, int level){
	hashTable[level]++;
	for(int j = 0; j < Node[index].size(); j++){//
		DFS(Node[index][j], level + 1);
	}
}

int main(){
	int n, m, parent, k, child;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &parent, &k);//父亲结点编号， 孩子个数
		for(int j = 0; j < k; j++){
			scanf("%d", &child);
			Node[parent].push_back(child);
		}
	}
	DFS(1,1);
	int maxLevel = -1, maxValue = 0;
	for(int i = 1; i < MAXN; i++){
		if(hashTable[i] > maxValue){
			maxValue = hashTable[i];
			maxLevel = i;
		}
	}
	printf("%d %d\n", maxValue, maxLevel);
	return 0;
}

//方法二 BFS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100];
int level [100];  //层数
int book[100];   //结点数
int main(){
	int n, m, a, k, c;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &c);
			v[a].push_back(c);
		}
	}
	queue<int> q;
	q.push(1);//根节点为1
	level[1] = 1;
	while(! q.empty()){
		int index = q.front();
		q.pop();
		book[level[index]]++;
		for(int i = 0; i < v[index].size(); i++){
			level[v[index][i]] = level[index] + 1;
			q.push(v[index][i]);
		}
	}
	
	int maxnum = 0, maxlevel = 1;
	for(int i = 1; i < 100; i++){
		if(book[i] > maxnum){
			maxnum = book[i];
			maxnum = i;
		}
	}
	printf("%d %d", maxnum, maxlevel);
	return 0;
}



