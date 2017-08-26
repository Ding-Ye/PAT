#include <cstdio>
int main()
{
	int n;
	int a[5];
	char b[5] = "SHCDJ";
	char c[5] = "SHCDJ";
	scanf("%d", &n);
	for(int i = 0; i < 5; i++){
		scanf("%d", &a[i]);
	}
	
	while(n){
		for(int i = 0; i < 5; i++){
			c[a[i]] = b[i];
		}
		
		for(int i = 0; i < 5; i++){
			b[i] = c[i];
		}
		
		n--;
	}
	
	for(int i = 0; i < 5; i++){
		printf("%c", c[i] );
	}	
	return 0;
}

//方法二
#include <cstdio>
const int N = 54;``
char mp [5] = {'S', 'H', 'C', 'D', 'J'};
int start[N+1], end[N+1], next[N+1];

int main()
{
	int k;
	scanf("%d", &k);
	for(int i = 1; i <= N; i++){
		start[i] = i;
	}
	
	for(int i = 1; i <=N; i++){
		scanf("%d", &next[i]);
	}
	
	for(int step = 0; step < k; step++){
		for(int i = 1; i <= N; i++){
			end[next[i]] = start[i];
		}
		for(int i = 1; i <= N; i++){
			start[i] = end[i];
		}
	}
	
	for(int i = 1; i <= N; i++){
		if(i != 1)
			printf(" ");
		start[i] --;
		printf("%c%d", mp[start[i] / 13], start[i] % 13 + 1 );
	}
	
	return 0;
}













