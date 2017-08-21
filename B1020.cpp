#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int kuche[a];
	for(int i = 0; i < a; i++){
		scanf("%d", &kuche[i]);
	}
	int jiage[a];
		for(int i = 0; i < a; i++){
		scanf("%d", &jiage[i]);
	}
	
	float junjia[a];
	for(int i = 0; i < a; i++){
		junjia[i] =float (kuche[i])/jiage[i]
	}
	
	float max = -1;
	for(int i = 0; i < a; i++){
		if()
	}
	return 0;
}

//方法二用结构体
#include <cstdio>
#include <algorithm>
using namespace std;
struct mooncake{
	double store;
	double sell;
	double price;
}cake[1010];

bool cmp(mooncake a, mooncake b){//按单价从高到低排序
	return a.price > b.price;
}

int main()
{
	int n;
	double D;
	scanf("%d %lf", &n, &D);
	for(int i = 0; i < n; i++){
		scanf("%lf", &cake[i].store);
	}
	for(int i = 0; i < n; i++){
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;
	}
	
	sort(cake, cake+n, cmp);//可以对结构体排序
	double ans = 0;
	for(int i = 0; i < n; i++){
		if(cake[i].store <= D){
			D -= cake[i].store;
			ans += cake[i].sell;
		}
		else{
			ans += cake[i].price*D;
			break;
		}
	}
	printf("%.2f\n", ans);
	return 0;
}