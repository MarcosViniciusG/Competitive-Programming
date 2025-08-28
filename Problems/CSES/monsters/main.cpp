#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using pii = pair<pi, int>;
using vpi = vector<pi>;
char grid[1000][1000];

int diry[4] = {1, -1, 0, 0};
int dirx[4] = {0, 0, 1, -1};

char moves[4] = {'D', 'U', 'R', 'L'};

signed main() {
    int n, m;
    cin >> n >> m;

    queue<pair<pi, char>> q;
    int visited[1000][1000];
    memset(visited, -1, sizeof(visited));
    int ya=-1, xa=-1;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
        cin >> grid[i][j];
        if(i==0 || i+1==n || j==0 || j+1==m) { 
            if(grid[i][j]=='A') {
                cout << "YES\n" << 0 << '\n';
                return 0;
            }
        }
        
        if(grid[i][j]=='A') {
            ya = i; xa = j;
        }
        else if(grid[i][j]=='M') {
            q.push({{i, j}, 'M'});
            visited[i][j] = -2;
        }
    }           

    q.push({{ya, xa}, 'A'});
    visited[ya][xa] = -2;

    bool ok = false;
    int gy=-1, gx=-1;
    while(!q.empty()) {
        pii u = q.front(); q.pop(); 
        int y = u.first.first;
        int x = u.first.second;
        char tipo = u.second;

        if(tipo=='A' && (y==0 || y+1==n || x==0 || x+1==m)) {
            ok = true;
            gy = y; gx = x;
            break;
        }

        for(int k=0; k<4; k++) {
            int ny = y + diry[k]; 
            int nx = x + dirx[k];
            if(ny >= n || ny < 0) continue;
            if(nx >= m || nx < 0) continue;
            if(grid[ny][nx]=='#') continue;
            if(visited[ny][nx]!=-1) continue;

            q.push({{ny, nx}, tipo});
            visited[ny][nx] = k;
        }
    }

    if(!ok)
        cout << "NO\n";
    else {
        cout << "YES\n";
        string ans="";
        int y = gy, x = gx;
        while(visited[y][x] != -2) {
            int k = visited[y][x];
            ans += moves[k];
            y -= diry[k];
            x -= dirx[k];
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        cout << ans << "\n";
    }

    return 0;
}