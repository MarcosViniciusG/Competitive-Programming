#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

void dfs(ll at, ll n ,vpll adj[], bool visited[]) {
    if(visited[at])
        return;

    visited[at] = true;
    cout << at << "\n";

    vpll neighbours = adj[at];
    for(auto nex: neighbours)
        dfs(nex.first, n, adj, visited);
} 

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a, b;

    // n is nodes and m is edges
    ll n, m;
    cin >> n >> m;

    // graph is weighted or not
    bool weighted;
    cin >> weighted;

    // graph is undirected or not
    bool undirected;
    cin >> undirected;

    vpll adj[n];
    ll weight;
    for(ll i=0; i<m; i++) {
        weight=1;
        cin >> a >> b;

        if(weighted) 
            cin >> weight;

        adj[a-1].push_back(make_pair(b-1, weight));
        if(undirected)
            adj[b-1].push_back(make_pair(a-1, weight));
    }

    bool visited[n] = {0};

    ll start_node=0;    
    dfs(start_node, n, adj, visited);
    
    return 0;
}