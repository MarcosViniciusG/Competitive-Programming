#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

pair<vll, vll> sieve(ll n) {
    vll ps, spf(n + 1);
    spf[1] = 1;
    for(ll i = 2; i <= n; i++) if (!spf[i]) {
        ps.eb(i);
        for (ll j = i; j <= n; j += i)
            if (!spf[j]) spf[j] = i;
    }
    return { ps, spf };
}

vll factors(ll x) {
    vll fs;
    
    return fs;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    ll M, N, K;
    cin >> M >> N >> K;

    ll MX = (ll)2e7 + 5e6;
    auto [ps, spf] = sieve(MX);
    // for (ll i = 0; i < 20; ++i)
    //     cout << ps[i] << ' ';
    // cout << '\n';
    map<ll, ll> raizquad;

    ll idx = lower_bound(all(ps), (ll)1e6) - ps.begin();
    for (ll i = idx; i < ps.size(); ++i)
        raizquad[ps[i] * ps[i]] = ps[i];

    vll value, ns(N + 1);
    for (ll i = 1; i <= N; ++i)
        cin >> ns[i];
    map<ll, vpll> h;

    while (K--) {
        ll m, n, d;
        cin >> m >> n >> d;
        h[ns[n]].eb(d, m);
    }

    for (auto& [n, xs] : h) {
        // cout << "n: " << n << '\n';
        ll x = n;
        if (x <= MX)
            while (x != 1) {
                // cout << "spf: " << spf[x] << '\n';
                value.eb(spf[x]);
                x /= spf[x];
            }
        else if (xs.size() == 1) {
            auto [d, m] = xs[0];
            if (d >= 3) {
                for (ll i = 2; i * i <= 1e6; ++i)
                while (x % i == 0) {
                    value.eb(i);
                    x /= i;
                }
                if (x > 1) value.eb(x);
            }
            if (d == 2)
                value.eb(raizquad[n]);
            else
                value.eb(n);
        }
        else {
            for (ll i = 2; i * i <= x; ++i)
                while (x % i == 0) {
                    value.eb(i);
                    x /= i;
                }
            if (x > 1) value.eb(x);
        }
    }

    sort(all(value));
    value.erase(unique(all(value)), value.end());

    for (ll x : value)
        cout << x << ' ';
    cout << '\n';
}