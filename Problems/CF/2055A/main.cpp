#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    int n, a, b;
    while(t--) {
        cin >> n >> a >> b;
        bool odd_a = (a & 1);
        bool odd_b = (b & 1);
        bool can = false;
        if(odd_a && odd_b || (!odd_a && !odd_b)) {
            can = true;
        }

        cout << (can ? "YES" : "NO") << '\n';
    }

    return 0;
}