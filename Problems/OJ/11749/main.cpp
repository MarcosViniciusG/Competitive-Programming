#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

void dfs(ll at, bool visited[], vpll graph[], pll &cc) {
    if(visited[at])
        return;

    visited[at] = true;

    vpll neighbours = graph[at];
    for(auto nex: neighbours) {
        if(!visited[nex.first])
            cc.first+=nex.second;

        dfs(nex.first, visited, graph, cc);
    }

}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n=1, m=1, a, b, w;
    while(n!=0 || m!=0) {
        cin >> n >> m;
        
        vpll graph[n];
        for(ll i=0; i<m; i++) {
            cin >> a >> b >> w;
            a--; b--;
            graph[a].push_back(make_pair(b, w));
            graph[b].push_back(make_pair(a, w));
        }

        bool visited[n] = {false};
        pll biggest_cc;
        ll j=0;
        for(ll i=0; i<n; i++) {
            if(!visited[i]) {
                pll cc = make_pair(j, 0);
                dfs(i, visited, graph, cc);
                if(!j)
                    biggest_cc = cc;
                else if(cc.first > biggest_cc.first)
                    biggest_cc = cc;
                j++;
            }
        }

        cout << biggest_cc.second << '\n';
    }

    return 0;
}