#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define eb emplace_back()

ll divisors(ll x) {
    ll qnt = 0;
    for (ll i = 1; i * i <= min(x, (ll)1e9); ++i)
        if (x % i ==0 ) {
            ++qnt;
            if (i * i != x && x / i <= (ll)1e9) ++qnt;
        }
    return qnt;
}

#define all(xs) xs.begin(),xs.end()
signed main() {
    ll n;
    cin >> n;
    vll xs(n);
    for (ll& x : xs) cin >> x;

    ll mn = *min_element(all(xs));
    for (ll& x : xs) x -= mn;
    ll g = 0;
    for (ll x : xs) g = gcd(g, x);

    cout << 1 << ' ' << divisors(g) - 1 << '\n';
}