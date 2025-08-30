#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define vvpll vector<vpll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define eb emplace_back()

pair<vll, vll> dijkstra(const vvpll &g, ll s) {
    vll ds(g.size(), LLONG_MAX), pre=ds;
    priority_queue<pll, vpll, greater<>> pq;
    ds[s] = 0, pq.emplace(ds[s], s);
    while(!pq.empty()) {
        auto [t, u] = pq.top(); pq.pop();
        if(t > ds[u]) continue;
        for(auto [w, v] : g[u]) {
            if(t+w < ds[v]) {
                ds[v] = t+w, pre[v] = u;
                pq.emplace(ds[v], v);
            }
        }
    }
    return {ds, pre};
}

signed main() {
    ll n, m, k;
    cin >> n >> m >> k;

    vvpll g(n);
    vector<set<ll>> tel(n);
    ll u, v, c;
    rep(i, 0, m) {
        cin >> u >> v >> c;
        u--; v--;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    ll t;
    ll ti;
    rep(i, 0, n) {
        cin >> t;
        rep(j, 0, t) {
            cin >> ti >> c;
            t
        }
    }
}