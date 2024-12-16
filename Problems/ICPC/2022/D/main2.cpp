#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define per(i, b, a) for (ll i = (b); i >= (a); --i)
#define x first
#define y second

ll n, t = 0, p, q;

ll half(ll x) {
    return ((1 << n) - x) / 2;
}

ll mn(ll x, ll y) {
    if (x == p and y == q)
        return 0;
    if (x == 0 or y == 0 or x == (1 << n) or y == (1 << n))
        return INT_MAX;
    cout << "x: " << x << " y: " << y << '\n';
    return 1 + min({mn(x / 2, y / 2), mn(half(x), y / 2), mn(x / 2, half(y)), mn(half(x), half(y)) });
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> p >> q;
    cout << mn(1 << (n - 1), 1 << (n - 1)) << '\n';    
    return 0;
}