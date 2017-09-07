#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
map<string, set<int>>mpTitle, mpAuthor, mpKey, mpPub, mpYear;

/*void query(map<string, set<int>>& mp, string& str)
{
	if(mp.find(str) == mp.end())
		printf("Not Found\n");
	else{
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++){
			printf("%07d\n", *it);
		}
	}
}*/

void query(map< string, set<int> > &m, string &str) {
    if(m.find(str) != m.end()) {
        for(set<int>::iterator it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);
    } else
        printf("Not Found\n");
}

int main()
{
	int n, m, id, type;
	string title, author, key, pub, year;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &id);
		char c = getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin, author);
		mpAuthor[author].insert(id);
		while(cin>>key){
			mpKey[key].insert(id);
			c = getchar();
			if(c == '\n')
				break;
		}
		
		getline(cin, pub);
		mpPub[pub].insert(id);
		
		getline(cin, year);
		mpPub[year].insert(id);
	}
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d: ", &type);
		string temp;
		getline(cin, temp);
		cout<< type << ": "<< temp<<endl;
		if(type == 1)
			query(mpTitle, temp);
		else if(type == 2) 
			query(mpAuthor, temp);
		else if(type == 3) 
			query(mpKey, temp);
		else if(type == 4) 
			query(mpPub, temp);
		else  if(type == 5) 
			query(mpYear, temp);
	}
	return 0;
}

//方法二
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
map<string, set<int> > title, author, key, pub, year;
void query(map< string, set<int> > &m, string &str) {
    if(m.find(str) != m.end()) {
        for(set<int>::iterator it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main() {
    int n, m, id, num;
    scanf("%d", &n);
    string ttitle, tauthor, tkey, tpub, tyear;
    for(int i = 0; i < n; i++) {
        scanf("%d", &id);
        getchar();//
        getline(cin, ttitle);
        title[ttitle].insert(id);
        getline(cin, tauthor);
        author[tauthor].insert(id);
        while(cin >> tkey) {
            key[tkey].insert(id);
            char c;
            c = getchar();
            if(c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num == 1) query(title, temp);
        else if(num == 2) query(author, temp);
        else if(num == 3) query(key, temp);
        else if(num == 4) query(pub,temp);
        else if(num ==5) query(year, temp);
    }
    return 0;
}


















