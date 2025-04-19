#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()
#define pll pair<ll, ll>
#define vpll vector<pll>
#define x first
#define y second

ll soma_digitos(ll x) {
    ll sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

signed main() {
    ll MAXN = 1e6;
    vll qnt(MAXN + 1);
    for (ll i = 1; i <= 9; ++i)
        qnt[i] = 1;
    for (ll i = 10; i <= MAXN; ++i)
        qnt[i] = qnt[i - soma_digitos(i)] + 1;

    ll n, k;
    cin >> n >> k;
    --k;
    vll xs(n);
    for (ll& x : xs)
        cin >> x;
    sort(all(xs), greater<>());

    // 3 2 1 1 
    // 8 8 8 8 7 7 7 6 6 5 4 3 2 1
    vll qnts(n);
    for (ll i= 0; i < n; ++i)
        qnts[i] = qnt[xs[i]];

    ll l = 0, r = 1;
    ll delta = 0;
    while (k and qnts[l] - delta > 0) {
        ll nr = r;
        while (qnts[nr] == qnts[l] - delta)
            ++nr;
        ll sz = nr - l;
        if (k - sz < 0) break;
        k -= sz;
        r = nr;
        ++delta;
    }

    // cout << "k: " << k << '\n';
    // cout << "delta: " << delta << '\n';
    // // xs[0 + k] -= delta;
    // cout << "xs[0+k]: " << xs[0+k] << '\n';
    // cout << "r: " << r << '\n';
    if (r > k)
        for (ll i = 0; i < delta; ++i)
            xs[0 + k] -= soma_digitos(xs[0 + k]);

    cout << soma_digitos(xs[0 + k]) << '\n';
}