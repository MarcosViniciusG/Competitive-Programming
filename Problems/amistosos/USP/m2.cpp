#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)


signed main() {
    ll n;
    cin >> n;
    n *= 2;
    vll xs(n);
    for (ll& x : xs) cin >> x;

    vll next(n + 1);

    // for (auto x : next) cout << x << ' ';
    // cout << '\n';

    vpll dp(n);
    dp[n - 1] = {0, 0};
    next[xs[n - 1]] = n - 1;
    per(i, n - 2, 0) {
        dp[i] = dp[i + 1];
        auto [bq, bc] = dp[i + 1];
        ll j = next[xs[i]];
        if (j == 0) {
            next[xs[i]] = i;
            continue;
        }
        auto [nbq, nbc] = dp[j];
        ll q = 1 + nbq;
        if (q > bq)
            dp[i] = { q, j - i + nbc};
        else if (q == bq)
            dp[i] = { q, min(j - i + nbc, bc)};
    }

    cout << dp[0].first << ' ' << dp[0].second << '\n';
}