#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int to_int(char c) {
    return c-'a'+1;
}

// p==31, only lowercase alphabet letters
ll h(string s) {
    ll ans=0, p=31, q=ll(1e9) + ll(7);

    for(auto c: s)
    {
        ans = (ans*p) % q;
        ans = (ans + to_int(c)) % q;
    }

    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b;
    cin >> a >> b;

    cout << (h(a)==h(b) ? "YES" : "NO") << '\n';
    return 0;
}