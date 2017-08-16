#include <iostream>
#include <string>
using namespace std;
int main()
{
	string n;
	string change[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	cin>>n;
	int sum = 0;
	for(int i = 0; i <n.size(); i++){
		sum += (n[i] - '0');
	}
	
	//如果将一个不知道位数的整数，将其中每一位提出来
	int num = 0, ans[10];
	while( sum != 0){
		ans[num] = sum%10;
		num++;
		sum /=10;
	}
	
	for(int i = num-1; i>=0; i--){
		cout<<change[ans[i]];
		if(i !=0)
			cout<<" ";
		else
			cout<<endl;
	}
	
	return 0;
}































