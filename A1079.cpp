#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node{
	double data;	//货物量
	vector<int> child; //指针域
}Node[maxn];
int n;
double p, r, ans = 0;
//用递归实现DFS， 注意二点。1.递归式  2.递归边界
void DFS(int index, int depth){
	//递归边界
	if(Node[index].child.size() == 0){
		ans += Node[index].data*pow(1+r, depth);
		return;
	}
	//递归式
	for(int i = 0; i <Node[index].child.size(); i++){
		DFS(Node[index].child[i], depth + 1);
	}
}

int main(){
	int k, child;
	scanf("%d %lf %lf", &n, &p, &r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		if(k == 0){//叶节点的标志
			scanf("%lf", &Node[i].data);
		}
		else{
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				Node.child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.lf\n", p*ans);
	return 0;
}


















