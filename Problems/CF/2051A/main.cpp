#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vll a(n);
        vll b(n);

        for(ll &i: a)
            cin >> i;

        for(ll &i: b)
            cin >> i;
        
        ll diff=a[n-1];
        for(ll i=1; i<n; i++) {
            if(a[i-1] > b[i])
                diff += (a[i-1] - b[i]);
        }

        cout << diff << '\n';
    }

    return 0;
}