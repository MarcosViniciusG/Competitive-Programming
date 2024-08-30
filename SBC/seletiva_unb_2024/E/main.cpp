#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    getline(cin, s);

    string ans="";
    cout << "|";

    for(int i=0; i<s.length(); i++) {
        ans += s[i];

        if(i!=(s.length()-1) && (s[i] >= s[i+1])) {
            cout << ans << '|';
            ans="";
        }
    }
    
    cout << ans << '|' << endl;

    return 0;
}