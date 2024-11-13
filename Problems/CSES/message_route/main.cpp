#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n, m;
vll solve(ll s, vll g[]) {
    bool visited[n] = {0};
    visited[s] = true;

    queue<ll> q;
    vll previous(n, -1);
    q.push(s);
    while(!q.empty()) {
        vll neighbours = g[q.front()];
        for(auto x: neighbours) {
            if(!visited[x]) {
                q.push(x);
                previous[x] = q.front();
                visited[x] = true;
            }
        }

        q.pop();
    }

    return previous;
}

vll reconstructPath(ll e, vll previous) {
    vll path;
    path.push_back(e);

    for(ll i=e; previous[i]!=-1; i=previous[i])
        path.push_back(previous[i]);

    reverse(path.begin(), path.end());
    return path;
} 

vll bfs(ll s, ll e, vll g[]) {
    vll previous = solve(s, g);

    vll path = reconstructPath(e, previous);
    return path;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a, b;
    cin >> n >> m;

    vll g[n];
    for(ll i=0; i<m; i++) {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    vll path = bfs(0, n-1, g);

    if(path[0]!=0)
        cout << "IMPOSSIBLE\n";
    else {
        cout << path.size() << '\n';
        for(auto e: path)
            cout << e+1 << ' ';
        cout << '\n';
    }

    return 0;
}