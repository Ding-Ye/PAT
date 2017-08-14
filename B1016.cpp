#include <iostream>
#include <string>
using namespace std;
int main(){
	string a, b;
	int m,n;
	cin >> a >> m >> b >>n;
	int lena = a.length();
	int lenb = b.length();
	int ta = 0;
	int tb = 0;
	
	for(int i = 0; i < lena; i++ ){
		if(m == (a[i] - '0'))
			ta = 10*ta + m;
	}
	
	for(int i = 0; i < lenb; i++ ){
		if(n == (b[i] - '0'))
			tb = 10*tb + n;
	}
	
	cout << ta + tb;
	return 0;
	
}

























