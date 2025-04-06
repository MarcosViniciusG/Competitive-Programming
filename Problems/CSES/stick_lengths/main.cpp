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

ll ans(vll &p, ll x) {
    ll res=0;
    for(auto e: p)
        res += abs(x-e);

    return res;
}

signed main() {
    fastio;
    ll n;
    cin >> n;

    vll p(n);
    for(ll &i: p) {
        cin >> i;
    }

    sort(all(p));
    
    cout << ans(p, p[n/2])  << '\n';

    return 0;
}