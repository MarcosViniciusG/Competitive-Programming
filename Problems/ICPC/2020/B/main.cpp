#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define all(xs) xs.begin(), xs.end()

signed main() {
    ll n;
    cin >> n;

    vector matriz(11, vector<bool>(11));

    for (ll i = 0; i < n; ++i) {
        ll d, l, r, c;
        cin >> d >> l >> r >> c;

        if (d == 0) {
            for (int j = c; j < c + l; ++j) {
                if (j > 10 or matriz[r][j]) {
                    cout << "N\n";
                    return 0;
                }
                matriz[r][j] = true;
            }
        }
        else {
            for (int j = r; j < r + l; ++j) {
                if (j > 10 or matriz[j][c]) {
                    cout << "N\n";
                    return 0;
                }
                matriz[j][c] = true;
            }
        }
    }

    cout << "Y\n";
}