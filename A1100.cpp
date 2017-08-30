1.map可以将任何基本类型(包过STL容器)映射到任何基本类型(包括STL容器)
1.什么是map
2.map有什么用
3.它有那些基本原理
4.map的底层任何实现(红黑树)  

map 任何定义
map 如何访问 访问的时候有个现象：map会以键从小到大的顺序自动排序
map 有那些函数（功能）find(key) erase() size() clear() 
map 的常见用途
1.字符与整数之间的映射问题
2.判断大整数或者其他类型数据是否存在问题
3.字符串和字符串的映射问题


c++ 标准库 cctype
字符处理库
功能1.字符串处理
isalnum()
isalpha()
iscntrl()
isdigit()
isgraph()
islower()
isprint()
ispunct()
isspace()
isupper()
isxdigit()

字符映射
tolower()
toupper()


明天查一下c++有哪些输入方式，以及各种方式输入的区别 c++的话应该只有cin 和cout
但是c++兼容c语言 scanf() prinf() / getchar()(读取一个单一的字符) putchar() / gets()(读取一行直到一个终止符或EOF) puts() 
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
//
#include <iostream>
#include <string>
#include <cctype>	//cctype是什么类型的头文件  字符库处理
using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct",
    "nov", "dec"};
string b[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy",
    "lok", "mer", "jou"};
void func1(string s) {
    int len = s.length();
    int num = 0;
    for (int i = 0; i < len; i++) {
        num = num * 10 + (s[i] - '0');
    }
    cout << b[num / 13];
    if((num % 13) && (num / 13)) {
        cout << " " << a[num % 13];
    } else if(num % 13) {
        cout << a[num % 13];
    } else if(num == 0) {
        cout << a[num % 13];
    }
}
 
void func2(string s) {
    int len = s.length();
    int num = 0;
    if(len == 4) {
        cout << 0;
        return ;
    } else if (len == 3) {
        for (int i = 1; i <= 12; i++) {
            if (s == a[i]) {
                cout << i;
                return ;
            }
            if (s == b[i]) {
                cout << i * 13;
                return ;
            }
        }
    } else {
        string temp1 = s.substr(0, 3);
        string temp2 = s.substr(4, 3);
        for (int i = 1; i <= 12; i++) {
            if (temp1 == b[i]) {
                num += i * 13;
            }
            if (temp2 == a[i]) {
                num += i;
            }
        }
        cout << num;
    }
    return ;
}
 
int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if(isdigit(s[0])) {
            func1(s);
        } else {
            func2(s);
        }
        cout << endl;
    }
    return 0;
}

















































