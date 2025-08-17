#include <bits/stdc++.h>

using namespace std;

int diry[4] = {1, -1, 0, 0};
int dirx[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};

int rev_diry[4] = {-1, 1, 0, 0};
int rev_dirx[4] = {0, 0, -1, 1};
char grid[1000][1000];

signed main() {
    int n, m;
    cin >> n >> m;

    int starty=0;
    int startx=0;

    int goaly=0;
    int goalx=0;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
        cin >> grid[i][j];
        if(grid[i][j]=='A') {
            starty = i;
            startx = j;
        }
        else if(grid[i][j]=='B') {
            goaly = i;
            goalx = j;
        }
    }
    
    queue<pair<int, int>> q;
    q.push({starty, startx});

    int visited[1000][1000];
    for(int i=0; i<1000; i++)
    for(int j=0; j<1000; j++)
        visited[i][j] = -1;

    visited[starty][startx] = -2;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        if(y==goaly && x==goalx)
            break;

        for(int k=0; k<4; k++) {
            int ny = y+diry[k], nx = x+dirx[k];
            if(ny >= n || ny < 0) continue;
            if(nx >= m || nx < 0) continue;
            if(grid[ny][nx]=='#') continue;
            if(visited[ny][nx]!=-1) continue;

            q.push({ny, nx});
            visited[ny][nx] = k;
        }

        q.pop();
    }

    if(visited[goaly][goalx]==-1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        string ans="";

        int y = goaly, x = goalx;
        while(grid[y][x] != 'A') {
            int k = visited[y][x];
            ans += dir[k];
            
            y += rev_diry[k];
            x += rev_dirx[k];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.length() << '\n';
        cout << ans << '\n';
    }
    

    return 0;
}