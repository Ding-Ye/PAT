//大小写问题,不知道为什么有一组数据不能通过
#include <cstdio>
#include <cstring>
int main()
{
	char a[100],b[100];
	scanf("%s %s",&a, &b);
	int lena = strlen(a);
	int lenb = strlen(b);
	char out[80];
	int j = 0;
	int k = 0;
	int index = 0;
	for(int i = 0; i < lena; i++){//用two point 只需要一遍遍历
		if(a[i] != b[j]){
			if(a[i] >= 'a' && a[i] <= 'z'){//这里掉了等于号
				out[index++] = a[i] - 32;//小写转换成大写
			}
			else{
				out[index++] = a[i];
			}
		}
		else{
			if(j < lenb)
				j++;
		}
	}

	for(int i = 1; i < index; i++){
		for(int j = 0; j < i; j++){
			if(out[i] == out[j]){
				out[i] = '#';
			}
		}
	}
	
	for(int i = 0; i < index; i++){
		if(out[i] != '#')
		printf("%c",out[i]);
	}
	return 0;
}

//方法二
#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	string a, b;
	cin>>a>>b;
	char c[80];
	int flag, index = 0;
	for(int i = 0; i < a.length(); i++){
		flag = 0;
		for(int j = 0; j < b.length(); j++){
			if(a[i] == b[j]){
				flag = 1;
				break;
			}
		}
		if(!flag)
			c[index++] = toupper(a[i]);//toupper(c)	假如c是小写字母，则返回大些字母形式，否则返回c。
	}
	for(int i = 1; i < index; i++){
		for(int j = 0; j < i; j++){
			if(c[i] == c[j]){
				c[i] = '#';
				break;
			}
		}
	}
	
	for(int i = 0; i < index; i++){
		if(c[i] != '#')
			cout<<c[i];
	}
	
	return 0;
}

























































