// modular arithmetic and multiset

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
        ll n, k;
        cin >> n >> k;

        multiset<ll> s;
        ll si;
        rep(i, 0, n) {
            cin >> si;
            si %= k;

            ll dist = abs(si - k);
            ll el = min(dist, abs(dist-k));
            s.insert(el);
        }
        
        multiset<ll> t;
        ll ti;
        rep(i, 0, n) {
            cin >> ti;
            ti %= k;

            ll dist = abs(ti - k);
            ll el = min(dist, abs(dist-k));
            t.insert(el);
        }

        // for(auto e: s)
        //     cout << e << ' ';
        // cout << '\n';
        // for(auto e: t)
        //     cout << e << ' ';
        // cout << '\n';

        if(t==s)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}