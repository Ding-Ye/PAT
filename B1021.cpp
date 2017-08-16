#include <iostream>
#include <string>
using namespace std;
int main()
{
	string n;
	cin>>n;
	int count[10] = {0};
	for(int i = 0; i<n.length(); i++){
		count[n[i] - '0'] ++;
	}
	
	for(int i = 0; i < 10; i++){
		if(count[i] != 0){
			printf("%d:%d\n",i, count[i]);
		}
	}
	return 0;
}