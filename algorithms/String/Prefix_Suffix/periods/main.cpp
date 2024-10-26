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
        if(is_suffix(s, pre))
            b=pre;
    }

    return b;
}

// Find all periods through borders size
vector<int> periods(string s) {
    string b = s;
    vector<int> sizes;
    while (b.length())
    {
        b = border(b);
        sizes.push_back(s.length()-b.length());
    }

    return sizes;
}

int main() {
    string s;
    getline(cin, s);

    vector<int> results = periods(s);
    for(auto p: results) {
        cout << p << ' ';
    }
    cout << '\n';

    return 0;
}