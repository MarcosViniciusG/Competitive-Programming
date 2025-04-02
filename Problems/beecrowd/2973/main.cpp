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
    ll n, c, t;
    cin >> n >> c >> t;

    vll p(n);
    vll pre;
    pre.push_back(0);
    ll co=0;
    for(ll &i: p) {
        cin >> i;
        pre.push_back(pre[co]+i);
        co++;
    }

    ll mx = n-(c > n ? n : c)+1;
    cout << mx << '\n';

    ll ans=pre[n];
    for(ll i=mx-1; i<n-1; i++) {
        ans = min(ans, pre[i+1]-pre[i-mx+1]); 
    }

    cout << ceil(double(ans) / t) << '\n';

    return 0;
}