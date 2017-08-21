//用结构体
//这个题目主要是
// 输入样例：
// 6
// 3-10 99
// 11-5 87
// 102-1 0
// 102-3 100
// 11-9 89
// 3-2 61
//如何把3-2 61得输入转变成3 2 61
//个人认为scanf printf 在输入形式的变化上比cin 和cout要强
#include <cstdio>
struct cheYu{
	int fen;
	int flag;
	int yuan;
} stu[10010];
int main()
{
	int n;
	int hashTable[1010] = {0};
	//int sum[1010] = {0};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d-%d %d", &stu[i].flag, &stu[i].yuan, &stu[i].fen);
		hashTable[stu[i].flag] += stu[i].fen;
	}
	//数组中找最大值
	int k = 0;
	for(int i = 0; i < 1010; i++){
		if(hashTable[k] < hashTable[i]){
			k = i;
		}
	}
	printf("%d %d\n", k, hashTable[k] );
	return 0;
}