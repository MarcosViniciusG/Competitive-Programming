#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define x first
#define y second
#define pll pair<ll>
#define vpll vector<pll>
#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (b); ++i)

signed main() {
    ll n, k;
    cin >> n >> k;
    vll parent(n + 1);
    vvll g(n + 1);
    rep(i, 0, n - 1) {
        ll x;
        cin >> x;
        parent[i + 2] = x;
        g[x].eb(i + 2);
        g[i + 2].eb(x);
    }
    parent[1] = 0;
    map<ll, set<ll>, greater<>> guys;
    vll depth(n + 1);
    auto dfs = [&](auto& self, ll u, ll p) -> void {
        if (g[u].size() == 1 and u != 1 and depth[u] != 0) {
            guys[depth[u]].erase(u);
            if (guys[depth[u]].size() == 0)
                guys.erase(depth[u]);
        }
        depth[u] = depth[p] + 1;
        for (ll v : g[u]) if (v != p)
            self(self, v, u);
        if (g[u].size() == 1 and u != 1)
            guys[depth[u]].emplace(u);
    };
    dfs(dfs, 1, 0);
    // // cout << guys.size() << '\n';
    // for (auto [d, guy] : guys) {
    //     for (ll x : guy)
    //         cout << x << ' ';
    //     cout << '\n';
    // }
    ll ans = 0;
    rep(i, 0, k) {
        ll u = *(guys.begin()->second.begin());
        guys.begin()->second.erase(u);
        if (guys.begin()->second.size() == 0)
            guys.erase(guys.begin());
        // cout << "u primeiro " << u << "\n";
        // depth[u] = 0;
        while (u != 0) {
            ++ans;
            depth[u] = 0;
            // cout << u << "\n";
            for (ll v : g[u]) if (v != parent[u] and depth[v] != 0)
                dfs(dfs, v, u);
            if (depth[parent[u]] == 0) break;
            u = parent[u];
        }
        // cout << "guys\n";
        // for (auto [d, guy] : guys) {
        //     for (ll x : guy)
        //         cout << x << ' ';
        //     cout << '\n';
        // }
        if (guys.empty()) break;
    }
    cout << ans << '\n';
}