#include <cstdio>
const int N = 110;
int father[N]; //存放父节点
bool isRoot[N]; //记录每个节点是否作为某个集合的根节点

int findFather(int x){ //查找x所在集合的根节点
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	//路径压缩（可不写）？？？
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Union(int a, int b){//合并a和b所在的集合
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

void init(int n){//初始化father[i]为i，且flag[i]为false
	for(int i = 1; i <= n; i++){
		father[i] = i;//每个节点都是自己根节点
		isRoot[i] = false;
	}
}

int main(){
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	init(n);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);//输入两个好朋友的关系
		Union(a, b);//合并a和b所在的集合
	}
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)] = true;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		ans += isRoot[i];
	}
	printf("%d\n", ans);
	return 0;
}

