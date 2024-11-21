#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;

vll graph[200010];
ll counter=0;
 
void dfs(ll at, bool visited[]) {
    if(visited[at])
        return;
    
    visited[at] = true;
    counter++;

    vll neighbours = graph[at];
    for(auto nex: neighbours) 
        dfs(nex, visited);
}


signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, M, a, b;
    
    cin >> N >> M;
    for(ll i=0; i<M; i++) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool visited[N] = {false};
    dfs(0, visited);

    bool al=false;
    for(ll i=0; i<N; i++) {
        if(!visited[i]) {
            al = true;
            cout << i+1 << '\n';
        }
    }

    if(!al)
        cout << "Connected\n";

    return 0;
}