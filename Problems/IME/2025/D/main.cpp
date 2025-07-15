#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, a, b) for(ll i= a; i< b; ++i)
#define eb emplace_back

void solve() {
    ll n, m; cin >> n >> m;
    vvll g(n + 1);
    vector adj(n + 1, vector<bool>(n + 1));

    rep(i, 0, m) {
        ll u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
        adj[u][v] = adj[v][u] = true;
    }

    vector<bool> visited(n + 1);

    auto dfs = [&](auto& self, ll u) -> bool {
        visited[u] = true;
        for (ll v : g[u]) {
            if (!visited[v]) {
                if (self(self, v))
                    return true;
            }
            else return true;
        }
        return false;
    };

    bool has_cycle = false;
    bool has_degree_be3 = false;

    for (ll i = 1; i <= n; ++i) {
        if (!visited[i])
            has_cycle |= dfs(dfs, i);
        if (g[i].size() >= 3)
            has_degree_be3 = true;
    }

    if (!has_cycle || !has_degree_be3) {
        cout << "NO\n";
        return;
    }

    visited = vector<bool>(n + 1);
    vector<bool> super_visited(n + 1);
    bool can = false;

    auto backtracking = [&](auto& self, vll& path, ll u) {
        path.eb(u);
        visited[u] = true;
        super_visited[u] = true;

        if (path.size() == 6) {
            if (adj[u][path[2]]) {
                cout << "YES\n";
                can = true;
                return;
            }
            visited[u] = false;
            path.pop_back();
        }

        for (auto v : g[u]) if (!visited[v]) {
            self(self, path, v);
            if (can) return;
        }

        visited[u] = false;
        path.pop_back();
    };

    rep(i, 1, n + 1)
        if (!super_visited[i]) {
            vll path;
            backtracking(backtracking, path, i);
            if (can) return;
        }

    cout << "NO\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll t = 1;
    cin >> t;
    while (t--) solve();
}