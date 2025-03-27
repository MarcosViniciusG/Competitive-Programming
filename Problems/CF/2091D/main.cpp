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

        ll l=0;
        ll r=m;

        while(r-l > 1) {
            ll mid = (r+l)/2;

            if(k <= n*(mid*(m/(mid+1)) + (m % (mid+1))))
                r = mid;
            else
                l = mid;
        }

        cout << l+1 << '\n';
    }

    return 0;
}