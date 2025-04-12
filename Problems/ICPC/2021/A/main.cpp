#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ll n;
    cin >> n;

    ll T = 0;
    ll D = 0;
    for (ll i = 0; i < n; ++i) {
        ll t, d;
        cin >> t >> d;
        if (d == D)
            T = t + 10;
        else 
            T = T + 10;
        D = d;
    }
    cout << T << '\n';
}