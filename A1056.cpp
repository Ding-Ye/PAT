 1.所谓的队就是一个数组加上一个双指针
 #include <cstdio>
 #include <queue>
 using namespace std;
const int maxn = 1010;
struct mouse{
	int weigth;
	int R;
}mouse[maxn];//结构体数组
int main()
{
	int np, ng, order;
	scanf("%d %d", &np, &ng);
	for(int i = 0; i < np; i++){
		scanf("%d", &mouse[i].weigth);
	}
	queue<int> q;
	for(int i = 0; i < np; i++){
		scanf("%d", &order);
		q.push(order);
	}
	int temp = np,;
	int group;
	while(q.size() != 1){
		if(temp % ng == 0)
			group = temp/ng;
		else
			group = temp/ng + 1;
		//枚举每一组
		for(int i = 0; i < group; i++){
			int k = q.front();//？？？
			for(int j = 0; j < ng; j++){
				if(i * ng + j >= temp)
					break;
				int front = q.front();
				if(mouse[front].weigth > mouse[k].weigth){
					k = front;
				}
				mouse[front].R = group + 1;
				q.pop();
			}
			q.push(k);//把胜利的老鼠晋级
		}
		temp = group;
	}
	mouse[q.front()].R = 1;
	for(int i = 0; i < np; i++){
		printf("%d", mouse[i].R);
		if(i < np - 1)
			printf(" ");
	}
	return 0;
}


























