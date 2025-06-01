#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); --i)
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

signed main() {
    ll n;
    cin >> n;
    vector<vector<long long>> g(n + 1);
    rep(i, 2, n + 1) {
        ll p; cin >> p;
        g[p].eb(i);
        g[i].eb(p);
    }
    string s;
    cin >> s;
    string r;
    ll ans = 0;
    vll bs(s.size() + 1, -1);
    ll t = -1;
    auto dfs = [&](auto& self, ll u, ll p, ll d) -> void {
        for (ll v : g[u]) if (v != p) {
            r += s[v - 2];

            ll bt = t;
            ll bbsd = bs[d + 1];

            while (t > -1 and r[t] != r[d])
                t = bs[t];
            bs[d + 1] = ++t;
            // cout << "bs[d + 1]: " << bs[d + 1] << ' ' << "v: " << v << '\n';

            ll periodo = (ll)r.size() - bs[d + 1];
            // cout << "periodo: " << periodo << '\n';
            // cout << "string: " << r << '\n';
            if (r.size() % periodo == 0 and periodo < r.size())
                ans = max(ans, periodo);

            self(self, v, u, d + 1);

            t = bt;
            bs[d + 1] = bbsd;

            r.pop_back();
        }
    };
    dfs(dfs, 1, 0, 0);

    cout << ans << '\n';
}