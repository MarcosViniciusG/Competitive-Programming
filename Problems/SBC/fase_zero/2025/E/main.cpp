#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); --i)
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

vll divisors(ll x) {
    vll ds;
    for (ll i = 1; i * i <= x; ++i)
        if (x % i == 0) {
            ds.eb(i);
            if (i * i != x) ds.eb(x / i);
        }
    return ds;
}

signed main() {
    ll y, k, x = 1, i = 0;
    cin >> y >> k;
    vll ds = divisors(y);
    sort(all(ds));

    // for (ll d : ds)
    //     cout << d << ' ';
    // cout << '\n';

    ll previous = ds[0];
    while (k and i + 1 < ds.size()) {
        // cout << "k: " << k << " ds[i + 1]: " << ds[i + 1] << " ds[i]: " << previous << " i: " << i << '\n';
        if ((ds[i + 1] - x) % previous == 0) {
            ll K = (ds[i + 1] - x)  / previous;
            x += previous * K;
            k -= K;
            previous = ds[i + 1];
        }
        ++i;
    }

    if (i == ds.size() - 1) 
        x += previous * k;

    cout << x << '\n'; 
}