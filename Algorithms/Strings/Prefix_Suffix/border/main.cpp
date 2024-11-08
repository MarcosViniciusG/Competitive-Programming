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

// Biggest non-trivial (distinct from string s) border
// Can find all borders too if modified
string border(string s) {
    string b="";
    string pre="";
    for(int i=0; i<s.size()-1; i++) {
        pre += s[i];
        if(is_suffix(s, pre))
            b=pre;
    }

    return b;
}

int main() {
    string s;
    getline(cin, s);

    string result = border(s);

    if(result=="")
        cout << "No border";
    else
        cout << result;
    cout << '\n';

    return 0;
}