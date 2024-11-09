#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n'

vll solve(ll s, ll n, vll adj[]) {
    bool visited[n] = {0};
    visited[s] = true;

    queue<ll> q;
    q.push(s);
    vll prev(n, -1);
    while (!q.empty())
    {
        vll neighbours = adj[q.front()]; 
        for(auto nex: neighbours) {
            if(!visited[nex]) {
                visited[nex]=true;
                q.push(nex);
                prev[nex] = q.front();
            }
        }
        q.pop();   
    }

    return prev;
}

vll reconstructPath(ll s, ll e, vll prev) {
    // Reconstruct path from e
    vll path;
    for(ll i=e; i!=-1; i=prev[i])
        path.push_back(i);

    reverse(path.begin(), path.end());

    if(path[0]==s) 
        return path;
    else {
        // Return empty vector
        vll place;
        return place;
    } 
}

vll bfs(ll s, ll e, ll n, vll adj[]) {

    // BFS starting at node s
    vll prev = solve(s, n, adj);

    return reconstructPath(s, e, prev);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a, b;

    // n is nodes and m is edges
    ll n, m;
    cin >> n >> m;

    // graph is undirected or not
    bool undirected;
    cin >> undirected;

    // unweighted graph
    vll adj[n];

    for(ll i=0; i<m; i++) {
        cin >> a >> b;

        adj[a-1].push_back(b-1);
        if(undirected)
            adj[b-1].push_back(a-1);
    }

    vll result = bfs(0, 11, n, adj);
    for(auto e: result)
        cout << e << " ";
    cout << '\n';

    return 0;
}