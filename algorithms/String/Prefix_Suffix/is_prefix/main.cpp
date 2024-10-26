#include <bits/stdc++.h>

using namespace std;

bool is_prefix(string s, string pre) {
    return (
     (s.size() >= pre.size()) &&
     (!s.compare(0, pre.size(), pre))
     );
}

int main() {
    string pre;
    getline(cin, pre);

    string s;
    getline(cin, s);

    // Check if pre is prefix of s
    if(is_prefix(s, pre))
        cout << "Yes";
    else
        cout << "No";

    cout << '\n';

}