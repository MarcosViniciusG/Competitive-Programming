#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()

signed main() {
    ll t, d, m;
    cin >> t >> d >> m;

    vll xs(m + 2);
    xs[0] = 0;
    xs[m + 1] = d;    
    for (ll i = 1; i <= m; ++i)
        cin >> xs[i];
    for (ll i = 0; i <= m; ++i) {
        if (xs[i + 1] - xs[i] >= t) {
            cout << "Y\n";
            return 0;
        }
    }
    cout << "N\n";
}