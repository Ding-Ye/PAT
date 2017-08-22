#include <cstdio>
#include <cstring>
int main()
{
	char str[10010];
	gets(str);
	int len = strlen(str);
	int hashTable[6] = {0};
	char pat[] = "PATest" ;
	for(int i = 0; i < len; i++){
		switch (str[i]){
			case 'P':	
				hashTable[0]++;
				break;
			case 'A':
				hashTable[1]++;
				break;
			case 'T':
				hashTable[2]++;
				break;
			case 'e':
				hashTable[3]++;
				break;
            case 's':
				hashTable[4]++;
				break;
            case 't':
				hashTable[5]++;
				break;		
            default:
				break;
		}
	}
	int man = 0;
	for(int i = 0; i < 6; i++){
		if(hashTable[man] < hashTable[i]){
			man = i;
		}
	}
	
	int max = hashTable[man];
	while(max){
		for(int i = 0; i < 6; i++){
			if(hashTable[i] != 0){
				printf("%c", pat[i]);
				hashTable[i]--;
			}
		}
		max--;
	}
	
	return 0;
}