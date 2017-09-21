#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int father[N];		//存放父亲结点
bool isRoot[N];   //记录每个结点是否作为某个集合的根节点
int course[N] = {0};

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	
	while(a != father[a]){//路径优化
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

void Uion(int a, int b){
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;
	}
}

void init(int n){
	for(int i = 1; i <= n; i++){
		father[i] = i;
		isRoot[i] = false;
	}
}

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n, k , h;
	scanf("%d", &n);
	init(n);
	for(int i = 1; i <= n; i++){
		scanf("%d:", &k);
		for(int j = 0; j < k; j++){
			scanf("%d", &h);
			if(course[h] == 0){
				course[h] = i;
			}
			Uion(i, findFather(course[h]));
		}
	}
	
	for(int i = 1; i <= n; i++){
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(isRoot[i] != 0){
			ans++;
		}
	}
	printf("%d\n", ans);
	sort(isRoot + 1, isRoot + n + 1, cmp);
	for(int i = 1; i <= ans; i++){
		printf("%d", course[i]);
		if(i < ans)
			printf(" ");
	}
	return 0;
}