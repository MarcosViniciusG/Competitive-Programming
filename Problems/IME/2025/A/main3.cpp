#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define rep(i, a, b) for(ll i = a; i< b; ++i)
#define per(i, a, b) for(ll i = a; i >= b; --i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

signed main() {
    ll n, k;
    cin >> n >> k;
    vll iqs(n);
    for (ll& iq : iqs) {
        cin >> iq;
        iq += 100;
    }

    vvvll dp(n, vvll(k + 1, vll(16000 + 1)));

    dp[0][0][0] = 1;
    dp[0][1][iqs[0]] = 1;

    rep(i, 1, n) {
        dp[i] = dp[i - 1];
    // for (vll& xs : dp[i])
    //     for (ll x : xs)
    //         cout << x << ' ';
    // cout << '\n';
        rep(j, 0, k + 1)
            rep(m, 0, 16000 + 1)
                if (m - iqs[i] >= 0 && j > 0)
                    dp[i][j][m] += dp[i - 1][j - 1][m - iqs[i]];
    }
    
    // for (ll x : dp[n - 1][0])
    //     cout << x << ' ';
    // cout << '\n';

    ll ans = accumulate(all(dp[n - 1][k]), 0LL);
    cout << ans << '\n';
}