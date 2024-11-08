#include <bits/stdc++.h>

using namespace std;

bool is_suffix(string s, string suf) {
    int n1 = s.size();
    int n2 = suf.size();
    return (
     (s.size() >= suf.size()) &&
     (!s.compare(n1 - n2, suf.size(), suf))
     );
}

string border(string s) {
    string b="";
    string pre="";
    for(int i=0; i<s.size()-1; i++) {
        pre += s[i];
        if(is_suffix(s, pre)) {
            b=pre;
        }
    }

    return b;
}

// Find smallest period possible
int period(string s) {
    return s.size() - border(s).size();
}

int main() {
    string s;
    getline(cin, s);
    cout << period(s) << '\n';


    return 0;
}