#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    bool have[26] = {false};
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(auto c: s) {
        have[tolower(c) - 'a'] = true;
    }

    bool can = true;
    for(int i=0; i<26; i++) {
        if(!have[i])
            can = false;
    }

    cout << (can ? "YES" : "NO") << '\n';

    return 0;
}