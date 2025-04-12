#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

signed main() {
    ll n;
    cin >> n;

    queue<ll> rs, ls;
    for (ll i = 0; i < n; ++i) {
        ll t, d;
        cin >> t >> d;
        if (d == 0)
            rs.emplace(t);
        else
            ls.emplace(t);
    }

    ll T = 0, D = -1;
    for (ll i = 0; i < n; ++i) {
        ll r = (rs.empty() ? INT_MAX : rs.front());
        ll l = (ls.empty() ? INT_MAX : ls.front());
        if (D == 1 and r < T) r = T;
        if (D == 0 and l < T) l = T;
        // cout << "r, l  " << r << ' ' << l << '\n';
        if (D == 0) {
            if (ls.empty() or r < l) {
                rs.pop();
                T = r + 10;
            }
            else {
                ls.pop();
                D = 1;
                T = l + 10;
            }
        }
        else if (D == 1) {
            if (rs.empty() or l < r) {
                ls.pop();
                T = l + 10;
            }
            else {
                rs.pop();
                D = 0;
                T = r + 10;
            }
        }
        else if (D == -1) {
            if (rs.empty() or l < r) {
                ls.pop();
                D = 1;
                T = l + 10;
            }
            else {
                rs.pop();
                D = 0;
                T = r + 10;
            }
        }
        // cout << "T:" << T << '\n';
    }
    cout << T << '\n';
}