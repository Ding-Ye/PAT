#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int address, data, next;
	int order;//无效节点记为maxn
}node[maxn];

bool cmp(Node a, Node b){
	return a.order < b.order;
}

int main()
{
	for(int i = 0; i < maxn; i++){
		node[i].order = maxn;
	}
	int begin, n, K, address;
	scanf("%d%d%d", &begin, &n, &K);
	for(int i = 0; i < n; i++){
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;//结构体数组，它的下标就是它的地址
	}
	int p = begin;
    int count = 0;
	while(p != -1){
		node[p].order = count++;
		p = node[p].next;
	}
	
	sort(node, node + maxn, cmp);//安装order排序 从小到大
	n = count;
	for(int i = 0; i < n/K; i++){
		for(int j = (i+1) * K - 1; j > i*K; j--){
			printf("%05d %d %05d\n", node[j].address, node[j].data, node[j-1].address);
		}
		//下面是每一块的最后一个结点的next地址的处理
		printf("%05d %d ", node[i*K].address, node[i*K].data);
		if(i < n/K - 1){
			printf("%05d\n", node[(i+2)*K-1].address);
		}
		else{
			if(n % K == 0){
				printf("-1\n");
			}
			else{
				printf("%05d\n", node[(i+1)*K].address);
				for(int i = n/K*K; i < n; i++){
					printf("%05d %d", node[i].address, node[i].data);
					if(i < n-1){
						printf("%05d\n", node[i+1].address);
					}
					else{
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}



//方法二
#include <iostream>
using namespace std;
int main(){
	int first , k, n;
	cin >> first >> n >> k;
	
	int temp;//把地址为temp的数的数值存入data[temp]中，把temp的下一个结点的地址存入next[temp]中
	int data[100005];
	int next[100005];
	for(int i = 0; i < n; i++){
		cin >> temp;
		cin >> data[temp];
		cin >> next[temp];
	}
	int list[100005];//结点存储
	int sum = 0; //不一定所有的输入的结点都是有用的，加个计数器
	while(first != -1){
		list[sum++] = first;
		first = next[first];
	}
	int result[100005];
	for(int i = 0; i < sum; i++){
		result[i] = list[i];
	}
	for(int i = 0; i < (sum - sum % k); i++){
		result[i] = list[i / k * k + k - 1 - i % k];
	}
	
	for(int i = 0; i < sum - 1; i++)
		printf("%05d %d %05d\n", result[i], data[result[i]], result[i+1]);
	
	printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
	return 0;
}
















