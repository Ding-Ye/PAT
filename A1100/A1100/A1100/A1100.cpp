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
        temp = pow((double)index, (double)p);
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
        dfs(index, tempSum + v[index], tempK + 1, facSum + index);//可以选自己
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