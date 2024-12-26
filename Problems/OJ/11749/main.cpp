#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

ll dfs(ll at, bool visited[], vpll graph[], ll maxw) {
    if(visited[at])
        return 0;

    visited[at] = true;
    
    vpll neighbours = graph[at];
    ll ans=1;

    for(auto nex: neighbours) {
        if(nex.second!=maxw) continue;
        ans += dfs(nex.first, visited, graph, maxw);
    }

    return ans;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m, a, b, w;

    cin >> n >> m;
    while(n!=0 && m!=0) {
        vpll graph[n];

        ll maxw=0;
        for(ll i=0; i<m; i++) {
            cin >> a >> b >> w;
            a--; b--;
            maxw = max(maxw, w);
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }

        bool visited[n] = {false};

        // for(ll i=0; i<n; i++) {
        //     for(auto par: new_graph[i]) {
        //         cout << i << ' ' << par.first << ' ' << par.second << '\n';
        //     }
        // }

        ll best_n=1;
        for(ll i=0; i<n; i++) {
            if(!visited[i]) {
                ll ans = dfs(i, visited, graph, maxw);
                best_n = max(best_n, ans);
            }
        }

        cout << best_n << '\n';
        cin >> n >> m;
    }

    return 0;
}