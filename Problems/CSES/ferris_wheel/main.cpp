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
    ll n, x;
    cin >> n >> x;
    vll p(n);

    for(ll &i: p)
        cin >> i;

    sort(p.begin(), p.end());
    ll ans=0;
    ll l=0;
    ll r=n-1;
    while(r-l >= 0) {
        if(p[r]+p[l] <= x) {
            ans++;
            r--;
            l++;
        }
        else {
            ans++;
            r--;
        }
    }

    cout << ans << '\n';

    return 0;
}