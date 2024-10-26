#include <bits/stdc++.h>

using namespace std;

bool is_prefix(string s, string pre) {
    return (
     (s.size() >= pre.size()) &&
     (!s.compare(0, pre.size(), pre))
     );
}

bool is_suffix(string s, string suf) {
    int n1 = s.size();
    int n2 = suf.size();
    return (
     (s.size() >= suf.size()) &&
     (!s.compare(n1 - n2, suf.size(), suf))
     );
}

bool is_border(string s, string b) {
    return(is_prefix(s, b) && is_suffix(s, b));
}

int main() {
    string b, s;
    getline(cin, b);
    getline(cin, s);

    if(is_border(s, b)) 
        cout << "Yes";
    else
        cout << "No";
    cout << '\n';

    return 0;
}