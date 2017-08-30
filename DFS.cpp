1.使用递归可以很好的实现深度优先搜索，但是使用递归时，系统会调用一个叫系统栈的东西来存放递归每一层的状态。因此使用递归来实现DFS的本质还是栈0.
#include <cstdio>
const int maxn = 30;
int n , v, maxValue = 0;
int w[maxn], c[maxn];

void DFS(int index, int sumW, int sumC){
	if(index == n){ //已经完成对n件物品的选择
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
	
	DFS(0, 0, 0);
	printf("%d\n", maxValue);
	return 0;
}

//序列A中n个数选k个数使得和为x，最大平方和为maxSumSqu
int n, k, x, maxSumSqu = -1, A[maxn];
vector<int> temp, ans;

void DFS(int index, int nowK, int sum, int sumSqu){
	if(nowK == k && sum == x){
		if(sumSqu > maxSumSqu){
			maxSumSqu = sumSqu;
			ans = temp;
		}
		return;
	}
	if(index == n || nowK > k || sum > x)
		return;
	temp.push_back(A[index]);
	DFS(index + 1, nowK + 1, sum + A[index], sumSqu + A[index] * A[index]);
	temp.pop_back();
	DFS(index + 1, nowK, sum, sumSqu);
	
}



















