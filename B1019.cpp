#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp1(char a , char b){
	return a > b;
}
bool cmp2(char a , char b){
	return a < b;
}
int main()
{
	char a[4];
	char b[] = "6147";
	//scanf("%s", &a);
	gets(a);
	if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]){
		printf("%s - %s = 0000\n", a, a);
		return 0;
	}
	
	//N的四位数不完全相等

	do{
		sort(a, a+4, cmp1);
		char temp[4];
		for(int i = 0; i < 4; i++){
			temp[i] = a[i];
		}

		sort (a, a+4, cmp2);
		int A = 0;
		for(int i = 0; i < 4; i++){
			
			 A = temp[i] - '0' + A*10;
		}
		int B = 0;
		for(int i = 0; i < 4; i++){
			 B = a[i] - '0' + B*10;
		}
		int cha = 0;
		cha = A - B;
		printf("%d - %d = %d\n", A, B, cha);

		a[3] = cha%10 + '0';
		a[2] = cha/10%10 + '0';
		a[1] = cha/100%10 + '0';
		a[0] = cha/1000 + '0';
		
	} while(a[0] != '6' || a[1] != '1' || a[2] != '7'|| a[3] != '4');//while(a != "6174")
	printf("\n");
	return 0;
}

//方法二
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}

void to_array(int n, int num[])
{
	for(int i = 0; i < 4; i++){
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[])
{
	int sum = 0;
	for(int i = 0; i < 4; i++){
		sum = sum*10 + num[i];
	}
	return sum;
}
int main()
{
	int n, MIN, MAX;
	scanf("%d", &n);
	int num[4];
	while(1){
		to_array(n, num);//数字转数组
		sort(num, num+4);
		MIN = to_number(num);
		sort(num, num+4, cmp);
		MAX = to_number(num);//数组转数字
		n = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if(n == 0 || n == 6174)
			break;
		
	}
	return 0;
}