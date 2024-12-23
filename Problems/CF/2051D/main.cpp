#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
 
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, x, y, ai;
    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        vll a(n);
 
        ll soma=0;
        for(ll i=0; i<n; i++) {
            cin >> a[i];
            soma += a[i];
        }

        sort(a.begin(), a.end());
        ll counter=0;
        for(ll i=0; i<n; i++) {
            // Interval of every j that is under the constraints
            ll lb = lower_bound(a.begin(), a.end(), soma - a[i] - y) - a.begin(); // Index of lower bound
            ll ub = upper_bound(a.begin(), a.end(), soma - a[i] - x) - a.begin(); // Index of upper bound

            counter += (ub - lb);

            // Remove every pair (i==j)
            if(soma - 2*a[i] >= x && soma - 2*a[i] <=y)
                counter--;
        }
 
        cout << (counter / 2) << '\n';
    }
 
    return 0;
}