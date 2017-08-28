#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n, k;
	char name[5];
	int count;
	int id;
	scanf("%d %d", &n, &k);
	vector <string> course(k);
	for(int i = 0; i < n; i++){
		scanf("%s %d", &name, &count);
		for(int j = 0; j < count; j++){
			scanf("%d", &id);
			course[id].push_back(name[5]);
		}
	}
	
	
	return 0;
}