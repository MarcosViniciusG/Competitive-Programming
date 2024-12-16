#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n;
    string s;
    cin >> n >> s;

    if(n > 26) {
        cout << -1 << '\n';
        return 0;
    }

    int hist[26] = {0};
    for(auto c: s) {
        hist[c-'a']++;
    }

    int counter=0;
    for(int i=0; i<26; i++) {
        counter += max(0, hist[i] - 1);
    }

    cout << counter << '\n';
    return 0;
}