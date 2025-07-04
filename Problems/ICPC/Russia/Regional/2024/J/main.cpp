#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)

pair<vll, ll> topoSort(const vvll& g) {
    ll n = g.size(), cycle_edges = 0;
    vvll ig(n);
    rep(u, 1, n)
        for (ll v : g[u])
            ig[v].eb(u);

    vll indegree(n), outdegree(n), res;
    vector<bool> done(n);

    set<tll> pq;
    rep(u, 1, n) {
        outdegree[u] = g[u].size();
        for (ll v : g[u])
            ++indegree[v];
    }

    rep(u, 1, n)
        pq.emplace(indegree[u], -outdegree[u], u);

    // for (auto [I, O, U] : pq)
    //     cout << U << ' ' ;
    // cout << '\n';
    while (!pq.empty()) {
        auto it = pq.begin();
        auto [i, o, u] = *it;
        // cout << "u: " << u << '\n';
        pq.erase(it);
        res.eb(u);
        done[u] = true;
        for (ll v : ig[u]) {
            ll erased = pq.erase({indegree[v], -outdegree[v], v});
            --outdegree[v];
            if (erased)
                pq.emplace(indegree[v], -outdegree[v], v);
        }
        for (ll v : g[u])
            if (!done[v]) {
                pq.erase({indegree[v], -outdegree[v], v});
                --indegree[v];
                pq.emplace(indegree[v], -outdegree[v], v);
            }
            else {
                ++cycle_edges;
            }
    }

    // cout << "size: ";
    // cout << res.size() << '\n';
    return { res, cycle_edges };
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vvll g(n + 1);
    rep(i, 0, m) {
        ll u, v;
        cin >> u >> v;
        g[u].eb(v);
    }    
    auto [order, cycle_edges] = topoSort(g);
    // cout << "cycle_edges: " << cycle_edges << '\n';
    if (cycle_edges >= m / 2 + 1)
        cout << -1 << '\n';
    else {
        for (ll u : order)
            cout << u << ' ';
        cout << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
}