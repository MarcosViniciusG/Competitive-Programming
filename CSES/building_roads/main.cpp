#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

void dfs(ll at, vll roads[], bool visited[], vll &con) {
    if(visited[at])
        return;

    visited[at] = true;

    con.push_back(at);
    vll neighbours = roads[at];

    for(auto nex: neighbours)
        dfs(nex, roads, visited, con);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m, a, b;
    cin >> n >> m;
    vll roads[n];

    for(ll i=0; i<m; i++) {
        cin >> a >> b;
        roads[a-1].push_back(b-1);
        roads[b-1].push_back(a-1);
    }

    bool visited[n] = {0};
    vector<vll> connected;

    for(ll i=0; i<n; i++) {
        if(visited[i])
            continue;
        
        vll con;
        dfs(i, roads, visited, con);
        connected.push_back(con);
    }

    vpll new_roads;
    for(ll i=1; i<connected.size(); i++) {
        pll road = {connected[i-1][0]+1, connected[i][0]+1};
        new_roads.push_back(road);
    }
    cout << new_roads.size() << '\n';

    for(auto par: new_roads)
        cout << par.first << " " << par.second << '\n';

    return 0;
}