1.DFS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, k , p, maxFacSum = -1;
vector<int>fac, ans, temp;
//power函数计算x^p
int power(int x){
	int ans = 1;
	for(int i = 0; i < p; i++){
		ans *= x;
	}
	return ans;
}

void init(){
	int i = 0, temp = 0;
	while(temp <= n){
		fac.push_back(temp);
		temp = power(++i);
	}
}
void DFS(int index, int nowK, int sum, int facSum){
	if(sum == n && nowK == k){
		if(facSum > maxFacSum){
			ans = temp;
			maxFacSum = facSum;
		}
			return;
	}
	if(sum > n || nowK > k)
		return;
	if(index - 1 >= 0){
		temp.push_back(index);
		DFS(index,nowK+1, sum+fac[index], facSum+index);
		temp.pop_back();
		DFS(index - 1, nowK, sum, facSum);
	}
}

int main(){
	scanf("%d %d% %d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if(maxFacSum == -1)
		printf("Impossible\n");
	else{
		printf("%d = %d^%d", n, ans[0], p);
		for(int i = 1; i < ans.size(); i++){
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}


//方法二
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
void init() {
    int temp = 0, index = 1;
    while(temp <= n) {//当i^p没有超过n时，不断把i^p加入fac
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}
void dfs(int index, int tempSum, int tempK, int facSum) {
    if(tempSum == n && tempK == k) {
        if(facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return ;
    }
    if(tempSum > n || tempK > k) return ;//没有答案
    if(index >= 1) {
        tempAns.push_back(index);
        dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        tempAns.pop_back();
        dfs(index - 1, tempSum, tempK, facSum);
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init();
    dfs(v.size() - 1, 0, 0, 0);
    if(maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}