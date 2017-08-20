//有一个测试用例没有通过不知道为什么
#include <cstdio>
#include <cstring>
int main()
{
		char a[100];
		char b[100001];
		scanf("%s %s", &a, &b);
		int lena = strlen(a);
	    int lenb = strlen(b);
		int flag = 0;
		for(int i = 0; i < lena; i++){
			if(a[i] == '+' ){
				flag = 1;
				a[i] = '?';//将上档键全部统一车‘？’
			}
		}
		
		if(flag){
			for(int i = 0; i < lenb; i ++){
				if(b[i] >='A' && b[i] <= 'Z')
					b[i] = '#';
			}
			
			for(int i = 0; i < lena; i++){
				if(a[i] == '?')
					continue;
				for(int j  = 0; j < lenb; j++){//去掉数字，和空格
					if((a[i] >='0' && a[i] <= '9') || a[i] == '_' || a[i] == ',' ||a[i] == '.' || a[i] == '-' ){
						if(a[i] == b[j]){
							b[j] = '#';
						}
					}
					else{//去掉字母
						if(a[i] == (b[j] -32) || a[i] == b[j])
							b[j] = '#';
					}
				}
				
			}
		}
		else{
				for(int i = 0; i < lena; i++){
					for(int j  = 0; j < lenb; j++){
						if((a[i] >='0' && a[i] <= '9') || a[i] == '_'|| a[i] == ',' ||a[i] == '.' || a[i] == '-' ){//去掉数字，和空格
							if(a[i] == b[j]){
								b[j] = '#';
							}
						}
						else{//去掉字母
							if((a[i] == (b[j] -32)) || a[i] == b[j])
								b[j] = '#';
						}
		           }
	           }
            }		
			
		for(int i = 0; i < lenb; i++){
			if(b[i] != '#')
				printf("%c", b[i]);
		 }
		 printf("\n");
		 return 0;
}