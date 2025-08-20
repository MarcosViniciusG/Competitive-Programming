#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

vi colors (100000, -1);
vi graph[100000];
bool impossible = false;

void dfs(int at, int color) {
    if(colors[at]!=-1)
        return;

    colors[at] = color;
    for(auto v: graph[at]) {
        if(colors[v]==colors[at])
            impossible = true;

        if(color==1)
            dfs(v, color+1);
        else if(color==2)
            dfs(v, color-1);
    }
    return;
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
        dfs(i, 1);

    if(impossible){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(int i=0; i<n; i++) {
        cout << colors[i] << ' ';
    }
    cout << '\n';


    return 0;
}