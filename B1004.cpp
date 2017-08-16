#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu{
	string name;
	string xuehao;
	int num;
};
int main()
{
	int n;
	cin>>n;
	vector<stu> vec(n);
	int mi = 101, ma = -1;//这一步非常关键
	for(int i = 0; i < n; i++){
		cin>>vec[i].name>>vec[i].xuehao>>vec[i].num;
		mi = min(mi, vec[i].num);
		ma = max(ma,vec[i].num);
	}
	
	for(int i = 0; i < n; i++){
		if(ma == vec[i].num){
			cout<<vec[i].name<<" "<<vec[i].xuehao<<endl;
			break;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(mi == vec[i].num){
			cout<<vec[i].name<<" "<<vec[i].xuehao<<endl;
			break;
		}
	}
	return 0;
	
}

















