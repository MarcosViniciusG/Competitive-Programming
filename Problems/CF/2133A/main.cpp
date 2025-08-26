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

        // if there are 2, it's only YES if a_1==a_0

        // i think the last element must be equal
        // to the first element, if this is true, then
        // the ans is "YES"

        vll a(n);
        bool rep;
        for(ll &i: a)
            cin >> i;

        bool ok=false;
        rep(i, 0, n) {
            rep(j, 0, n) {
                if(a[i]==a[j] && i!=j)
                    ok = true;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}