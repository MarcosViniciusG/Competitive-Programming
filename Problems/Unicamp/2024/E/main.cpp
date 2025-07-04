#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()

tuple<ll, ll, ll> diophantine(ll a, ll b, ll c= 1) {
    if (b == 0) {
        if (c % a !=  0) return {LLONG_MAX, LLONG_MAX, a};
        return {c / a, 0, a};
    }
    auto [x, y, d] = diophantine(b, a % b, c);
    if (x == LLONG_MAX) return {x, y, a};
    return {y, x - a/b * y, d};
} 

void solve() {
    ll n, k;
    cin >> n >> k;
    vll xs(n);
    for (ll& x : xs) cin >> x;
    ll sum = accumulate(all(xs), 0LL);

    for (ll i = 0; i < n; ++i) {
        ll a = xs[i], b = sum - n * xs[i];
        // cout << "A: " << a << " B: " << b << '\n';
        auto [x, y, d] = diophantine(a, b, k);
        if (x != LLONG_MAX) {
            cout << "YES\n";
            for (ll k = 0; k < n; ++k) {
                if (k == i)
                    cout << x - y * (n - 1) << (k == n - 1 ? "" : " ");
                else
                    cout << y << (k == n - 1 ? "" : " ");
            }
            cout << '\n';
            return;
        }
    }

    cout << "NO\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) solve();
}
