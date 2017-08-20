#include <cstdio>
#include <cstring>
const int MAXN = 1010;
int hashTabe[256] = {0};
int main()
{
	char str[MAXN];
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len; i ++){//将字符串字母中的大写变成小写
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] += 32;
		}
	}
	
	for(int i = 0; i < len; i++){
		hashTabe[str[i]]++;
	}
	int ma = -1;
	char word ;
	for(int i =97; i < 123; i++){
		ma = ma > hashTabe[i] ? ma : hashTabe[i];
	}
	for(int i =97; i < 123; i++){
		if(hashTabe[i] == ma)
			printf("%c ", i);
	}
	printf("%d\n", ma);
	return 0;
}

//方法二
#include <cstdio>
#include <cstring>
const int maxn = 1010;
char str[maxn];
int hashTabe[30] = {0};
int main()
{
	gets(str);
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			hashTabe[str[i] - 'a']++;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z'){
			hashTabe[str[i] - 'A']++;
		}
	}
	int k = 0;
	for(int i = 0; i < 26; i++){
		if(hashTabe[i] >hashTabe[k]){
			k = i;
		}
	}
	printf("%c %d\n", 'a'+k, hashTabe[k]);
	return 0;
}