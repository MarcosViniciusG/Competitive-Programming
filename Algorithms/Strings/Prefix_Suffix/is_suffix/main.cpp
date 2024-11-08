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

int main() {
    string suf;
    getline(cin, suf);

    string s;
    getline(cin, s);

    // Check if suf is suffix of s
    int n1 = s.size();
    int n2 = suf.size();
    if(is_suffix(s, suf))
        cout << "Yes";
    else
        cout << "No";

    cout << '\n';

}