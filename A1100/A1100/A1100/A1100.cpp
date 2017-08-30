#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170];    //数字 -> 火星文
map<string, int>  strToNum; //它是怎么做映射 火星文 - 数字 map就是一种k-v结构
void init()
{
	for(int i = 0; i < 13; i++){
		numToStr[i] = unitDigit[i];//数字 -> 火星文
		strToNum[unitDigit[i]] = i;  //火星文 - 数字
		numToStr[i*13] = tenDigit[i];
		strToNum[tenDigit[i]] = i*13;
	}
	for(int i = 1; i < 13; i++){//十位
		for(int j = 1; j < 13; j++){//个位
			string str = tenDigit[i] + " " + unitDigit[j];
			numToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}
}
int main()
{
	init(); //打表 ：在程序中一次性计算出所有需要用的结果，之后的查询直接取这些结果就行
	int T;
	cin>>T;
	getchar();
	while(T--){
		string str;
		getline(cin, str);//不能用cin，用“cin>>”从输入流提取数据，遇空格就终止
		if(str[0] >= '0' && str[0] <= '9'){//字符转换成数字
			int num = 0;
			for(int i = 0; i < str.length(); i++){
				num = num * 10 + (str[i] - '0');
			}
			cout << numToStr[num] << endl;
		}
		else{
			cout << strToNum[str] << endl;
		}
	}
	return 0;
}