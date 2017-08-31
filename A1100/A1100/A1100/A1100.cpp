#include <cstdio>
const int maxn = 30;
int n , V, maxValue = 0;
int w[maxn], c[maxn];

//这就好像一个二叉树
void DFS(int index, int sumW, int sumC){
	if(index == n){ //已经完成对n件物品的选择（递归边界）
			if(sumW <= V && sumC > maxValue){
				maxValue = sumC;
			}
			return ;
	}
	
	//岔道口
	DFS(index + 1, sumW, sumC); //不选第index 件物品
	DFS(index + 1, sumW + w[index], sumC + c[index]);//选第index 件物品
}

int main()
{
	scanf("%d %d", &n, &V);
	for(int i = 0; i < n; i++){
		scanf("%d", &w[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	
	DFS(0, 0, 0);//初始时为第0件物品，当前总重量和总价值均为0
	printf("%d\n", maxValue);
	return 0;
}