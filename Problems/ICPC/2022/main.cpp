#include <bits/stdc++.h>

#ifdef LOCAL
#include "dbg.h"
#else
#define dbg(...)
#endif

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
#define vvll vector<vll>

pair<vvll, map<ll, vll>> kosaraju(const vvll& g) {
    vvll g_inv(g.size()), g_cond(g.size());
    vector<bool> vs(g.size());
    vll order, reprs(g.size());
    map<ll, vll> scc;

    auto dfs = [&vs](auto&& self, const vvll& h, vll& out, ll u) -> ll {
        ll repr = u;
        vs[u] = true;
        for (ll v : h[u]) if (!vs[v])
            repr = min(repr, self(self, h, out, v));
        out.emplace_back(u);
        return repr;
    };

    rep(u, 1, g.size()) {
        for (ll v : g[u])
            g_inv[v].emplace_back(u);
        if (!vs[u])
            dfs(dfs, g, order, u);
    }

    vs.assign(g.size(), false);
    reverse(all(order));

    for (ll u : order)
        if (!vs[u]) {
            vll cc;
            ll repr = dfs(dfs, g_inv, cc, u);
            scc[repr] = cc;
            for (ll v : cc)
                reprs[v] = repr;
        }

    rep(u, 1, g.size()) {
        for (ll v : g[u])
            if (reprs[u] != reprs[v])
                g_cond[reprs[u]].emplace_back(reprs[v]);
    }

    return {g_cond, scc};
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    ll n, m;
    cin >> n >> m;

    vvll g(n + 1);
    while (m--) {
        ll u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
    }

    auto [g_cond, scc] = kosaraju(g);

    if (scc.size() == 1) {
        cout << 0 << '\n';
        return 0;

    }

    vll degree(g_cond.size());
    rep(i, 1, g_cond.size()) {
        for (auto u : g_cond[i])
            degree[u]++;
    }

    ll ans = 0;
    dbg(g_cond, scc);
    for (auto& [r, cc] : scc) {
        if (degree[r] == 0) {
            ans++;
            continue;
        }
        ans += g_cond[r].size() == 0;
    }

    cout << ans - 1 << '\n';
    return 0;
}