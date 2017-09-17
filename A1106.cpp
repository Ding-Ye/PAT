#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
const double INF = 1e12;
vector<int> Node[maxn];
int n, num = 0;
double p, r, ans = INF;
void DFS(int index, int depth){
	if(Node[index].size() == 0){
		double price = p *pow(1+r, depth);
		if(price < ans){
			ans = price;
			num = 1;
		}
		else if(price == ans){
			num++;
		}
		
		return;
	}
	
	for(int i = 0; i < Node[index].size(); i++){
		DFS(Node[index][i], depth + 1);
	}
}

int main(){
	int k, child;
	scanf("%d %lf %lf", &n, &p ,&r);
	r /= 100;
	for(int i = 0; i < n; i++){
		scanf("%d %lf %lf", &n, &p, &r);
		if(k != 0){
			for(int j = 0; j < k; j++){
				scanf("%d", &child);
				Node[i].push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.4f %d\n", ans, num);
	return 0;
}


//方法二
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100005];
int mindepth = 99999999, minnum = 1;
void dfs(int index, int depth) {
    if(mindepth < depth)
        return ;
	
    if(v[index].size() == 0) {
        if(mindepth == depth)
            minnum++;
        else if(mindepth > depth) {
            mindepth = depth;
            minnum = 1;
        }
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, k, c;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[i].push_back(c);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", p * pow(1 + r/100, mindepth), minnum);
    return 0;
}













