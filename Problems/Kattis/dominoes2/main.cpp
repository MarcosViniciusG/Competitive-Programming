#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

ll dfs(ll at, vll graph[], bool visited[]) {
    if(visited[at])
        return 0;
    
    visited[at] = true;

    vll neighbours = graph[at];
    ll ans=1;
    for(auto nex: neighbours) {
        ans += dfs(nex, graph, visited);
    }
    return ans;
}

signed main() {
    ll t, n, m, l, x, y, z;
    cin >> t;

    while(t--) {
        cin >> n >> m >> l;
        vll graph[n];

        for(ll i=0; i<m; i++) {
            cin >> x >> y;
            x--; y--;
            graph[x].push_back(y);
        }

        vll start_nodes;
        for(ll i=0; i<l; i++) {
            cin >> z;
            z--;
            start_nodes.push_back(z);
        }

        ll ans=0;
        bool visited[n] = {false};
        for(auto node: start_nodes) {
            ans += dfs(node, graph, visited);
        }

        cout << ans << '\n';
    }

    return 0;
}