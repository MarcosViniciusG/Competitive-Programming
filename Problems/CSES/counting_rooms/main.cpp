#include <bits/stdc++.h>

using namespace std;

char grid[1000][1000];
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};
int n, m;
int ff(int y, int x) {
    if(y >= n || y < 0) return 0;
    if(x >= m || x < 0) return 0;
    if(grid[y][x]!='.') return 0;
    
    grid[y][x] = '#';
    for(int k=0; k<4; k++)
        ff(y+diry[k], x+dirx[k]);
    return 1;
}

signed main() {
    cin >> n >> m;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        cin >> grid[i][j];
    
    int ans = 0;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        ans += ff(i, j);

    cout << ans << '\n';
}