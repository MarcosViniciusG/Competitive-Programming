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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vll p(n);
        rep(i, 0, n) {
            cin >> p[i];
        }

        if(n==2) {
            rep(i, 0, n) {
                cout << 3 - p[i] << ' ';
            }
            cout << '\n';
            continue;
        }

        rep(i, 0, n) {
            cout << (n - p[i] == 0 ? n : n - p[i]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}