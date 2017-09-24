1.哈夫曼树（又称最优二叉树）
	1.1定义
		已知n个数，寻找一棵树，使得树的所有叶子节点的权值恰好为这n个数，并且使得这棵树的带权路径长度最小。
		
	2.怎么得到哈夫曼树
		1.初始状态下共有n个节点，将它们视作为n棵只有一个结点的树
		2.合并其中根节点权值最小的两棵树。生成两棵树根节点的父节点，权值为这两个根节点的权值之和，这样树的数量就减少一个
		3.重复2，直到只剩下一棵树为止
		
	3.代码实现（用优先队列也就是堆结构）
		#include <cstdio>
		#include <queue>
		using namespace std;
		
		priority_queue<long long, vector<long long>, greater<long long>> q;//小顶堆的优先队列
		
		int main(){
			int n;
			long long temp, x, y, ans = 0;
			scanf("%d", &n);
			for(int i = 0; i < n; i++){
				scanf("%lld", &temp);
				q.push(temp);
			}
			
			while(q.size() > 1){
				x = q.top();
				q.pop();
				y = q.pop();
				q.pop();
				q.push(x + y);
				ans += y + x;
			}
			printf("%lld\n", ans);
			return 0;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		