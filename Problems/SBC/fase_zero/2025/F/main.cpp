#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); --i)
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) xs.find(x) != xs.end()
#define eb emplace_back

signed main() {
    ll n;
    cin >> n;
    vll xs(n);
    for (ll& x : xs) cin >> x;
    sort(all(xs));

    ll MAXSUM = 4e3;

    // sum, qnt
    vector<map<ll, ll>> dp(4 + 1);

    for (ll x : xs) {
        if (x >= 0) {
            per(soma, MAXSUM, -MAXSUM)
                per(qnt, 4, 2) 
                    if (found(soma - x, dp[qnt - 1]))
                        dp[qnt][soma] += dp[qnt - 1][soma - x];
        }
        else { 
            rep(soma, -MAXSUM, MAXSUM + 1)
                rep(qnt, 2, 4 + 1) 
                    if (found(soma - x, dp[qnt - 1]))
                        dp[qnt][soma] += dp[qnt - 1][soma - x];
        }
        ++dp[1][x];
    }

    ll q;
    cin >> q;

    while (q--) {
        ll soma;
        cin >> soma;
        cout << dp[4][soma] << '\n';
    }
}