#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using pii = pair<pi, int>;
using vpi = vector<pi>;
char grid[1000][1000];

int diry[4] = {1, -1, 0, 0};
int dirx[4] = {0, 0, 1, -1};

int rev_diry[4] = {-1, 1, 0, 0};
int rev_dirx[4] = {0, 0, -1, 1};

char moves[4] = {'D', 'U', 'R', 'L'};
char rev_moves[4] = {'U', 'D', 'L', 'R'};

signed main() {
    int n, m;
    cin >> n >> m;

    queue<pii> q;
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
            ya = i;
            xa = j;
        }
    }           

    q.push({{ya, xa}, 0});
    priority_queue<pii> pq;

    int visited[1000][1000];
    memset(visited, 0, sizeof(visited));
    while(!q.empty()) {
        pii u = q.front(); q.pop(); 
        int y = u.first.first;
        int x = u.first.second;
        int dist = u.second;

        for(int k=0; k<4; k++) {
            int ny = y + diry[k]; 
            int nx = x + dirx[k];

            if(ny >= n || ny < 0) continue;
            if(nx >= m || nx < 0) continue;
            if(grid[ny][nx]=='#') continue;
            if(visited[ny][nx]) continue;

            q.push({{ny, nx}, dist+1});

            visited[ny][nx] = 1;
        }
    }

    return 0;
}