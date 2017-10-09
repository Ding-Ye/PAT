#include<iostream>
using namespace std;
int main()
{
    int  d[8];
    memset(d, 1, 8*sizeof(int));
    for(int i=0;i<8; i++)
		cout<<d[i]<<" ";
    cout<<endl;

    system("pause");
	return 0;
}