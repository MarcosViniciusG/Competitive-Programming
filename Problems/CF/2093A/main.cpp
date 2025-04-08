#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, k;
    cin >> t;
    while(t--) {
        cin >> k;

        cout << ((k & 1) ? "YES" : "NO") << '\n';
    }

    return 0;
}