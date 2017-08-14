//1int的范围[-2^32,2^32-1]
#include <cstdio>
int main()
{
	int T, tcase = 1;
	scanf("%d", &T);
	while(T--){
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a+b > c){
			printf("Case #%d: ture\n", tcase++);
		}
		else{
			printf("Case #%d: false\n", tcase++);
		}
	}
	return 0;
}

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long int a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i + 1 << ": ";
        if (a + b > c) {
            cout << "true";
        } else {
            cout << "false";
        }
        cout << endl;
    }
    return 0;
}