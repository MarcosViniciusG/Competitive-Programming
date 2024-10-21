#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    ll l, r, x;
    cin >> l >> r >> x;

    ll ci;
    vector<ll> c;

    for(ll i=0; i<n; i++) {
        cin >> ci;
        c.push_back(ci);
    }

    ll ways=0;
    for(int bit=0; bit<(1 << n); bit++) {
        ll td=0;
        ll big = 0;
        ll small = 1e7;
        ll np = 0;

        for(int i=0; i<n; i++) {
            if((bit & (1 << i)) != 0) {
                np++;
                td+=c[i];

                big = max(c[i], big);
                small = min(c[i], small);
            }
        }

        if((np >= 2) && ((big-small) >= x) && (td >= l) && (td <= r))
            ways++;
    }

    cout << ways << endl;

}