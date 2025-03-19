#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

signed main() {
    fastio;
    ll n, m;
    cin >> n >> m;

    multiset<ll> h;
    ll hi;
    for(ll i=0; i<n;i ++) {
        cin >> hi;
        h.insert(hi);
    }

    ll ans=0;
    ll ti;
    for(ll i=0; i<m; i++) {
        cin >> ti;
        auto it = h.lower_bound(ti);
        if(*it!=ti) {
            if(it==h.begin()) 
                cout << -1 << '\n';
            else {
                it--;
                cout << *it << '\n';
                h.erase(it);
            }
        }
        else {
            cout << ti << '\n';
            h.erase(it);
        } 
    }

    return 0;
}