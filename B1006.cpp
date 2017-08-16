#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int b = n/100;
	int s = n%100/10;
	int g = n%10;
	int m = 0;
	for(int i = 0; i < b; i++){
		cout<<"B";
	}
	for(int i = 0; i < s; i++){
		cout<<"S";
	}
	for(int i = 0; i <g; i++){
		m = i+1;
		cout<<m;
	}
	return 0;
}