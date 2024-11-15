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

## Flood Fill
`O(n+m)`

**2D MATRIX (IMPLICIT GRAPH)**
- Returns size of connected component
- Variation of DFS/BFS

```cpp
int dir_y[] = {};
int dir_x[] = {};

int floodfill(int i, int j, char c1, char c2) {
    if ((i < 0) || (i >= n)) return 0;
    if ((j < 0) || (j >= m)) return 0;
    if (grid[i][j] != c1) return 0;

    int ans = 1;
    grid[i][j] = c2;

    for (int d = 0; d < 8; ++d)
        ans += floodfill(i+dir_y[d], j+dir_x[d], c1, c2); 

    return ans;
}
```