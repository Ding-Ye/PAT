#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int cn1=0, cn2=-1, cn3=0, cn4=0, cn5=0;
	int num1=0, num2=0,num3=0,num4=0;
	float num3f=0;
	vector <int> vec(n);
	for(int i = 0; i < n; i++){
		cin >> vec[i];
		if(vec[i] % 5 == 0){
			if(vec[i] % 2 ==0)
				num1 += vec[i];
		}
		else if(vec[i] % 5 == 1){
			cn2 *= -1;
			num2 += (vec[i]*cn2);
		}
		else if(vec[i] % 5 == 2){
			cn3++;
		}
		else if(vec[i] % 5 == 3){
			cn4++;
			num3 += vec[i];
			num3f = float(num3)/cn4;
		}
		else {
			num4 = max(num4,vec[i]);
		}
	}

	if(num1 != 0)
		cout <<num1<<" ";
	else
		cout<<"N"<<" ";
	if(num2 != 0)
		cout <<num2<<" ";
	else
		cout<<"N"<<" ";
	if(cn3 != 0)
		cout <<cn3<<" ";
	else
		cout<<"N"<<" ";
	if(num3f != 0)
		printf("%.1f ",num3f);
	else
		cout<<"N"<<" ";
	if(num4 != 0)
		cout <<num4;
	else
		cout<<"N";
	
	return 0;
}