#include <cstdio>
using namespace std;
const int Galleon = 17*29;
const int Sickle = 29;
int main()
{
	int a1, b1, c1;
	int a2, b2, c2;
	scanf("%d.%d.%d %d.%d.%d",&a1, &b1, &c1, &a2, &b2, &c2);
	int prince = a1*Galleon + b1*Sickle + c1;
	int money = a2*Galleon + b2*Sickle + c2;
	int change = money - prince;
	if(change < 0){
		printf("-");
		change = -change;
	}
	printf("%d.%d.%d\n", change/Galleon, change%Galleon/Sickle,change%Sickle);
	return 0;
}