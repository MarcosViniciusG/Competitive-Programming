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
void dfs(ll at, ll n ,vll adj[], bool visited[]) {
    if(visited[at])
        return;

    visited[at] = true;

    vll neighbours = adj[at];
    for(auto nex: neighbours)
        dfs(nex, n, adj, visited);
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

## Topological Sort (Directed Acyclic Graph)

### DFS Variation
`O(n+m)`
```cpp
void dfs(ll at, ll n ,vpll adj[], bool visited[], vll &ts) {
    if(visited[at])
        return;

    visited[at] = true;

    vpll neighbours = adj[at];
    for(auto nex: neighbours)
        dfs(nex.first, n, adj, visited);
    ts.push_back(at);                       // Only change
}
```

### Kahn's Algorithm
- Result may differ from the DFS variation topological sort
- Modified BFS, but uses a priority queue
- Prioritizes lower index vertices first

**NEED TO CALCULATE IN DEGREE OF EACH VERTICE**
```cpp
priority_queue<ll, vll, greater<ll>> pq;
for(ll at=0; at<n; at++)        // Push all sources of connected components in graph 
    if(in_degree[at] == 0)
        pq.push(at);

while(!pq.empty()) {
    ll at = pq.top(); pq.pop();
    vll neighbors = adj[at];
    for(auto nex: neighbors) {
        in_degree[nex]--;
        if(in_degree[nex]>0) continue;
        pq.push(nex);
    }
}

```

## Bipartite Graph Check (Undirected Graph)
`O(n+m)`

- BFS variation
- If layer i has the color 0, then layer i+1 has color 1

```cpp
bool isBipartite(ll s, ll n, vll adj[]) {

    queue<ll> q;
    q.push(s);
    vll color(n, -1); color[s]=0;
    bool flag = true;
    while (!q.empty())
    {
        vll neighbours = adj[q.front()]; 
        for(auto nex: neighbours) {
            if(color[nex] == -1) {
                color[nex] = 1-(color[q.front()]);
                q.push(nex);
            }
            else if(color[nex] == color[q.front()]) {
                flag = false;
                break;
            }
        }
        q.pop();   
    }

    return flag;
}
```

## Cycle Check (Directed Graph)
```cpp
enum { UNVISITED = -1, VISITED = -2,  EXPLORED=-3};

void cycleCheck(ll at, ll n ,vll adj[], int visited[], ll dfs_parent[]) {
    visited[at] = EXPLORED;

    vll neighbours = adj[at];
    for(auto nex: neighbours) {
        cout << "Edge (" << at << " " << nex << ") is a ";
        if(visited[nex] == UNVISITED) {
            cout << "Tree Edge\n";
            dfs_parent[nex] = at;
            cycleCheck(nex, n, adj, visited);
        }
        else if(visited[nex] == EXPLORED) {
            if(nex == dfs_parent[at])
                cout << "Bidirectional Edge\n"; // Trivial cycle
            else
                cout << "Back Edge (Cycle)\n"; // Non trivial cycle

        }
        else if(visited[nex] == VISITED)
            cout << "Forward/Cross Edge\n";
    }

    visited[at] = VISITED;
}
```