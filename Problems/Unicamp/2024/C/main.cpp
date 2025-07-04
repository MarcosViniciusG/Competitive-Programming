#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd_(ll a, ll b) {
    // cout << "A: " << a << '\n';
    // cout << "B: " << b << '\n';
    if (a == b) return 0;
    if (b == 0) return 0;
    return a / b + gcd_(b, a % b);
}

signed main() {
    ll t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll ans = gcd_(a, b);
        if (ans != 0)
            cout << ans - 1 << '\n';
        else cout << 0 << '\n';
    }
}