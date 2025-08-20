#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

vi visited(100000, -1);
vi graph[100000];
int en=-1;
int start=-1;

void dfs(int at, int prev) {
    if(visited[at]!=-1) 
        return;

    visited[at] = prev;
    for(auto e: graph[at]) {
        if(visited[e]!=-1 && e!=prev && en==-1) {
            en = at;
            start = e;
        }

        if(visited[e]==-1)
            dfs(e, at);
    }
}

signed main() {
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n; i++)
        dfs(i, -2);

    if(en==-1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        vi ans;
        ans.push_back(start+1);
        int at = en;
        while(at!=start) {
            ans.push_back(at+1);
            at = visited[at];
        }

        ans.push_back(start+1);
        cout << ans.size() << '\n';
        for(int i=ans.size()-1; i>=0; i--)
            cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}