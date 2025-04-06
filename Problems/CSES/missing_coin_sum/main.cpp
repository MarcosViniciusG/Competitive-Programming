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
    ll n;
    cin >> n;

    vll x;
    ll xi;
    ll off=0;
    for(ll i=0; i<n; i++) {
        cin >> xi; 
        if(xi==1) off++;
        else x.push_back(xi);
    }
    off++;

    sort(all(x));
    ll soma=0;
    for(ll i=0; i<n; i++) {
        soma += x[i];
        x.push_back(soma);
    }
    sort(all(x));

    ll ans=(ll)1e18;
    for(ll i=0; i<(ll)x.size(); i++) {
        ll res = x[i] + off;
        auto it = lower_bound(all(x), res);
        if(*it!=res) {
            ans = res;
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}