#include <bits/stdc++.h>

using namespace std;

string build(int n) {
    string ans;
    for(int k=0; k<(1<<n); k++) {
        if(__builtin_popcount(k) & 1)
            ans += 'b';
        else
            ans += 'a';
    }

    return ans;
}

signed main() {
    int n;
    cin >> n;
    cout << build(n) << '\n';

    return 0;
}