#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T, typename S = null_type>
using oset = tree<T, S, less<>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); --i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin >> n;

    vll ms;
    vvll points(10, vll(86400));
    vvll comeco(10, vll(86400));

    rep(i, 0, n) {
        ll m;
        cin >> m;
        rep(i, 0, m) {
            ll l, r, pontos;
            cin >> l >> r >> pontos;
            points[i][r - 1] = pontos;
            comeco[i][r - 1] = l;
            ms.eb(r);
            ms.eb(l)
        }
    }
    sort(all(ms));

    vvll dp(86400, vll(10))[1025];

    ll max_anterior = 0;

    for (ll x : ms) {
        ll max_agora = 0;
        rep(j, 0, n) {
            rep(k, 0, 1025)
            if (points[j][i] != 0) {
                dp[i][j][k] = points[j][i] + dp[comeco[j][i]][j][];
            }
            dp[i][j] = max(dp[i][j], max_anterior);
            max_agora = max(max_agora, dp[i][j]);
        }
        max_anterior = max_agora;
    }

    cout << max_anterior << '\n';
}