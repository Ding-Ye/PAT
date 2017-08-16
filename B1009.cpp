//用栈这种数据结构就简单很多
#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<string> v;
	string s;
	while(cin>>s){
		v.push(s);
	}
	cout << v.top();
	v.pop();
	while(! v.empty()){
		cout<<" "<<v.top();
		v.pop();
	}
	return 0;
}