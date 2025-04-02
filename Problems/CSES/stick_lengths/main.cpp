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

ll result(vll &p, ll x) {
    ll res=0;
   for(auto e: p) 
        res += (x-e);

    return res;
}

ll ans(vll &p, ll x) {
    ll res=0;
    for(auto e: p)
        res += abs(x-e);

    return res;
}

signed main() {
    // fastio;
    ll n;
    cin >> n;

    vll p(n);
    ll mx=0;
    ll mn=(ll)1e18;
    ll soma=0;
    for(ll &i: p) {
        cin >> i;
        mx = max(mx, i);
        mn = min(mn, i);
        soma+=i;
    }

    ll media = soma/n;
    ll r=mx;
    ll l=mn;
    ll m = (r+l)/2;
    ll prev = result(p, media);
    while(r-l>1) {
        ll m=(l+r)/2;
        if(result(p, m) > prev)
            r = m;
        else
            l = m;
        prev = result(p, m);
    }

    cout << mx << " " << mn << "\n";
    cout << r << ' ' << l << "\n";
    cout << min({ans(p, l), ans(p, r)}) << '\n';

    return 0;
}