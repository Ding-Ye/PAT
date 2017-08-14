#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, m;
	int num;
	cin >> n >> m;
	vector <int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	int k;
	for (int j = 0; j < m; j++) {
		k = vec[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			vec[i + 1] = vec[i];
		}
		vec[0] = k;
	}

	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;

}





















