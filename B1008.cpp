#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	int num;
	cin>>n>>m;
	vector <int> vec(n);
	for(int i = 0; i < n; i++){
		cin >>vec[i];
	}
	
	int k;
	for(int j = 0; j < m ; j++){
		k = vec[n-1];
		for(int i =n-2; i >=0; i--){
			vec[i+1] = vec[i];
		}
		vec[0] = k;
	}
	
    for(int i = 0; i < n-1; i++){
		cout<<vec[i]<<" ";
	}	
	cout<<vec[n-1];
	return 0;
	
}

//方法二
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (m != n && m != 0) {
        if (m > n) m = m - n;
        reverse(begin(a), begin(a) + n);
        reverse(begin(a), begin(a) + m);
        reverse(begin(a) + m, begin(a) + n);
    }
    for (int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1];
    return 0;
}




















