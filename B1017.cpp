#include <cstdio>
#include <cstring>
int maxn = 1001;
struct begin{
	int d[maxn];
	int len;
	begin(){//begin 的构造函数 也就是一个初始化函数
		memset(d, 0, sizeof(d));
		len = 0;
	}
}；

bign change (char str[]){//字符串数组变成int数组
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++){
		a.d[i] = str[a.len - i- 1] - '0';
	}
	return a;
}

int divide(begin a, int b){
	bign c;
	int r = 0;
	c.len = a.len;
	for(int i = a.len - 1; i >= 0; i--){
		r = r * 10 + a.d[i];
		if(r < b)
			c.d[i] = 0;
		else{
			c.d[i] = r / d;
			r = r % d;
		} 
	}
	
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0){
		c.len--;
	}
	
	for(int i = 0; i < c.len; i++){
		printf("%d", c.d[i]);
	}
	printf(" ");
	return r;
}

int main()
{
	char a[maxn];
	int b;
	scanf("%s %d", &a, &b);
	begin a1= change(a);
	int c = divide(a1, b);
	printf("%d\n", c);
	
	return 0;
}