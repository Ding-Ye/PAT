#include <iostream>
#include <cstdio>
using namespace std;

void Swap(char* &pstr, char* &qstr){
	char *t = pstr;
	pstr = qstr;
	qstr = t;
}

int main(){
	char *pstr = "china";
	char *qstr = "america";
	Swap(pstr, qstr);
	cout<<pstr<<endl;
	cout<<qstr<<endl;
	return 0;
}