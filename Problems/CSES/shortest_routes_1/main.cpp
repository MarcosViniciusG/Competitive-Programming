#include <bits/stdc++.h>
using namespace std;

using ll =            long long;
#define vll           vector<ll>
#define vvll          vector<vll>
#define pll           pair<ll, ll>
#define vpll          vector<pll>
#define vvpll         vector<vpll>
#define endl '\n'
#define all(xs)       xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())

vvpll adj(1e5);

ll n, m;

void dijkstra(ll s, vll & d, vll & p) {
    d.assign(n, LLONG_MAX);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<pll, vpll, greater<pll>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

signed main() {
    cin >> n >> m;

    ll a, b, c;
    for(ll i=0; i<m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
    }

    vll d, p;
    dijkstra(0, d, p);

    for(ll i=0; i<n; i++)
        cout << d[i] << ' ';
    cout << '\n';

    return 0;
}