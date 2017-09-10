1链表排序
#include <cstdio>
#include <algorithm>
using namespace std;
struct NODE{
	int address;
	int key;
	int next;
	bool flag;
}node[100000];
int cmp(NODE A, NODE b){
	if(a.flag == false || b.flag == false){
		return a.flag > b.flag;// 把flag==true的排在前面
	}
	else{
		return a.key < b.key;
	}
}

int main(){
	int n , cnt = 0, s, a, b, c;
	scanf("%d%d", &n, &s);
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &a, &b, &c);
		node[a].address = a;
		node[a].key = b;
		node[a].next = c;
	}
	for(int i = s; i != -1; i = node[i].next){
		node[i].flag = true;
		cnt++;
	}
	if(cnt == 0){
		printf("0 -1");
	}
	else{
		sort(node, node+100000, cmp1);
		printf("%d %05d\n", cnt, node[0].address);
		for(int i = 0; i < cnt; i++){
			printf("%05d %d", node[i].address, node[i].key);
			if(i != cnt-1)
				printf("%05d\n", node[i+1].address);
			else
				printf("-1\n");
		}
	}
	return 0;
}














