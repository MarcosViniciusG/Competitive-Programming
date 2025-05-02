#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define x first
#define y second
#define pll pair<ll>
#define vpll vector<pll>
#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (b); ++i)
#define all(xs) xs.begin(), xs.end()


ll ceilDiv(ll a, ll b) {
    return a / b + (a % b != 0);
}

signed main() {
    ll n, c, t;
    cin >> n >> c >> t;
    vll xs(n);

    rep(i, 0, n)
        cin >> xs[i];
    ll hi = ceilDiv(accumulate(all(xs), 0LL), t);
    ll lo = 0;

    while (lo + 1 < hi) {
        ll mi = lo + (hi - lo) / 2;
        ll cost = 1, sum = 0;
        rep(i, 0, n)
            if (ceilDiv(xs[i], t) > mi)
                cost = c + 1;
        if (cost == 1) {
            rep(i, 0, n) {
                if (ceilDiv(sum + xs[i], t) <= mi)
                    sum += xs[i];
                else {
                    ++cost;
                    sum = xs[i];
                }
            }
        }
        // cout << "mi: " << mi << '\n';
        // cout << "cost: " << cost << '\n';
        if (cost > c)
            lo = mi;
        else
            hi = mi;
    }
    cout << hi << '\n';
}