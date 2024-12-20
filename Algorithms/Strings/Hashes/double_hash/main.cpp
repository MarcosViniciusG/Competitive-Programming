#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int to_int(char c) {
    return c-'a'+1;
}

ll hi(string s, ll p, ll q) {
    ll ans=0;

    for(auto c: s) {
        ans = (ans * p) % q;
        ans = (ans + to_int(c)) % q;
    }

    return ans;
}

pll h(string s) {
    ll p1 = 31;
    ll p2 = 29;
    ll q1 = ll(1e9) + ll(7);
    ll q2 = ll(1e9) + ll(9);

    return {hi(s, p1, q1), hi(s, p2, q2)};
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s, t;
    cin >> s >> t;

    pll sh = h(s);
    pll st = h(t);

    cout << (sh==st ? "YES" : "NO") << '\n';

    return 0;
}