#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string s, t;
    getline(cin, s);
    map<string, int> m;
    for(int i = 0; i < s.length(); i++) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
            t += s[i];
        } else {
            if(t.length())
                m[t]++;
            t = "";
        }
    }
    if(t.length()) m[t]++;
    int maxn = 0;
    for(map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
        if(it->second > maxn) {
            maxn = it->second;
            t = it->first;
        }
    }
    cout << t << " " << maxn;
    return 0;
}