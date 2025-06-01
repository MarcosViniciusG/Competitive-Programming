#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ll x;
    cin >> x;

    x *= (ll)8e6;
    ll ans = 0;
    while (x) {
        x /= 2;
        ++ans;
    }
    cout << ans << '\n';
}