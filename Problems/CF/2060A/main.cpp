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
        ll a[5];
        for(ll i=0; i<4; i++) {
            if(i>=2)
                cin >> a[i+1];
            else
                cin >> a[i];
        }

        ll best=0;
        for(ll i=-400; i<=400; i++) {
            a[2] = i;
            ll fib=0;
            for(ll j=2; j<5; j++) {
                if(a[j]==a[j-1]+a[j-2])
                    fib++;
            }
            best = max(best, fib);
        }

        cout << best << '\n';
    }

    return 0;
}