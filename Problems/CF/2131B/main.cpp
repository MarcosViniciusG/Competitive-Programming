// build

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

        vll a(n);
        rep(i, 0, n) {
            if(i%2==0) {
                a[i] = -1;
            }
            else {
                a[i] = 3;
            }
        }

        if(n%2==0) {
            a[n-1] = 2;
        }

        for(auto e: a)
            cout << e << ' ';
        cout << '\n';

    }

    return 0;
}