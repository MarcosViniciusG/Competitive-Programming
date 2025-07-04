#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main() {
    int n;
    cin >> n;

    ll uns = 0;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x == 1)
            ++uns;
    }
    cout << n - uns << '\n';
}