#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

bool visited[200010];

ll bfs(ll s, vll grid[]) {
    queue<ll> q;
    q.push(s);
    visited[s] = true;
    vll nodes;
    nodes.push_back(s);
    while(!q.empty()) {
        ll u = q.front(); q.pop();

        for(auto nex: grid[u]) {
            if(!visited[nex]) {
                q.push(nex);
                visited[nex] = true;
                nodes.push_back(nex);
            }
        }
    }

    ll n = nodes.size();

    ll edges=0;
    for(auto e: nodes) 
        edges += (grid[e].size());
    edges /= 2;

    ll mx = n*(n-1)/2;
    return mx - edges;
}

signed main() {
    fastio;
    memset(visited, false, sizeof(visited));
    ll N, M;
    cin >> N >> M;    

    vll grid[N];
    ll a, b;
    for(ll i=0; i<M; i++) {
        cin >> a >> b;
        a--; b--;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }

    ll ans=0;
    for(ll i=0; i<N; i++) {
        if(!visited[i]) {
            ans += bfs(i, grid);
        }
    }

    cout << ans << '\n';
    return 0;
}