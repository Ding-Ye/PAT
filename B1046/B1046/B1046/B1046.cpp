#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >>n;
	int a1, a2, b1, b2;
	int count1 = 0;
	int count2 = 0;
	for(int i = 0; i < n; i++){
		cin >>a1>>a2>>b1>>b2;
		if(a1+b1 != a2 && a1+b1==b2)
			count1++;
		else if(a1+b1 == a2 && a1+b1!=b2)
			count2++;
		else;
	}
	cout<<count1<<" "<<count2<<endl;
	return 0;
}