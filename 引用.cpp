1.引用形式上：就是给某个变量取个别名
2.其目的：主要用于函数参数传递中，解决大块数据或对象的传递效率和空间问题
3.引用与指针的区别：指针通过某个指针变量指向一个对象后，对它所指向的变量间接操作
#include <iostream>
using namespace std;

void swap(int& p1, int& p2){//
	int p;
	p = p1;
	p1 = p2;
	p2 = p;
	//cout<<p1 <<"哈哈"<<p2 <<endl;
} 

int main(){
	int a, b;
	cin >> a >> b;
	swap(&a, &b);
	cout<<a <<" "<<b;

	return 0;
}



1.使用指针作为函数的参数虽也能达到与使用引用的效果
#include <iostream>
using namespace std;

void swap(int* p1, int* p2){//
	int p;
	p = *p1;
	*p1 = *p2;
	*p2 = p;
	//cout<<p1 <<"哈哈"<<p2 <<endl;
} 

int main(){
	int a, b;
	cin >> a >> b;
	swap(&a, &b);
	cout<<a <<" "<<b;

	return 0;
}