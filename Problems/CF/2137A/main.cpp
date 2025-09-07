#include <bits/stdc++.h>
using namespace std;

#define dedinhos cin.tie(0)->sync_with_stdio(0)
using ll = long long;
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for(ll i = (a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (a); i >= (ll)(b); --i)
#define eb emplace_back


signed main() {
    dedinhos;

    int t;
    cin >> t;
    while(t--) {
        int k, x;
        cin >> k >> x;

        ll ans=x;
        rep(i, 0, k) {
            ans *= 2;
        }

        cout << ans << '\n';
    }

    return 0;
}