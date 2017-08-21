#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int a[10];
	for(int i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a+10);
	if(!a[0]){
		for(int i = 1; i < 10; i++){
			if(a[i]){
				a[0] = a[i];
				a[i] = 0;
				break;
			}
		}
		
		for(int i = 0; i < 10; i++){
			printf("%d", a[i]);
		}
	}
	else{
		for(int i = 0; i < 10; i++){
			printf("%d", a[i]);
		}
	}
	
	return 0;
}

//方法二
#include <cstdio>
int main()
{
	int count[10];
	for(int i = 0; i < 10; i++){
		scanf("%d", &count[i]);
	}
	
	for(int i = 1; i < 10; i++){
		if(count[i] > 0){
			printf("%d", i);
			count[i]--;
			break;
		}
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < count[i]; j++){
			printf("%d", i);
		}
	}
	return 0;
}