# Graph

## DFS
`O(n+m)`

**ADJACENCY LIST**

- Useful for detecting and finding cycles in a graph
- Compute a graph's minimum spanning tree
- Check if a graph is bipartite
- Find strongly connected components
- Topologically sort the nodes of a graph
- Find bridges and articulation points
- Find augmenting paths in a flow network
- Generate mazes

```cpp
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

    vpll neighbours = adj[at];
    for(auto nex: neighbours)
        dfs(nex.first, n, adj, visited);
}
```

## BFS
`O(n+m)`

**ADJACENCY LIST**

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

void bfs(ll s, ll n, vll adj[]) {
    bool visited[n] = {0};
    visited[s] = true;

    queue<ll> q;
    q.push(s);
    while (!q.empty())
    {
        vll neighbours = adj[q.front()]; 
        for(auto nex: neighbours) {
            if(!visited[nex]) {
                visited[nex]=true;
                q.push(nex);
            }
        }
        q.pop();   
    }
}
```

### Shortest path on unweighted graph
`O(n+m)`

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

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
```