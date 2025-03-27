#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;

    cin >> t;
    while(t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        
        ll lmt = ceil(m / 2.0);
        ll cols = ceil((double)k / double(n));

        ll ans=1;
        if(cols==m)
            ans=m;
        else if(cols > lmt) {
            ans = cols-lmt+1;
        }

        cout << ans << '\n';
    }

    return 0;
}