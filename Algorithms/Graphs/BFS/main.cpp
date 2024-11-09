#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n'

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
        cout << q.front() << '\n';
        q.pop();   
    }
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

    bfs(0, n, adj);

    return 0;
}