#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    while(getline(cin, s), s!="*") {
        char first = s[0];

        bool is = true;
        for(int i=1; i<s.size(); i++) {
            if(s[i]==' ') {
                if(tolower(s[i+1])!=tolower(first))
                    is = false;
            }
        }

        if(is)
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}