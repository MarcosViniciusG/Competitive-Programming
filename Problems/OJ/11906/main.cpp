#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T, R, C, M, N, W, xi, yi;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> R >> C >> M >> N;
        cin >> W;

        int grid[R][C] = {0};
        bool visited[R][C];
        memset(visited, false, sizeof(visited));

        for(int i=0; i<W; i++) {
            cin >> xi >> yi;
            grid[xi][yi] = 1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        int evens=0, odds=0;
        while(!q.empty()) {
            pair<int, int> u = q.front(); q.pop();
            int x = u.first;
            int y = u.second;
            if(visited[x][y])
                continue;

            visited[x][y] = true;

            int i, j;
            
            int moves=0;

            i = x+M;
            j = y+N;
            set<pair<int, int>> st;
            if(i < R && j < C && grid[i][j]!=1) {
                st.insert({i, j});
            }
            
            j = y-N;
            if(i < R && j >= 0 && grid[i][j]!=1) {
                st.insert({i, j});
            }

            i = x-M;
            j = y+N;
            if(i >= 0 && j < C && grid[i][j]!=1) {
                st.insert({i, j});
            }

            j = y-N;
            if(i >= 0 && j >=0 && grid[i][j]!=1) {
                st.insert({i, j});
            }

            i = x+N;
            j = y+M;
            if(i < R && j < C && grid[i][j]!=1) {
                st.insert({i, j});
            }
            
            j = y-M;
            if(i < R && j >= 0 && grid[i][j]!=1) {
                st.insert({i, j});
            }
            
            i = x-N;
            j = y+M;
            if(i >= 0 && j < C && grid[i][j]!=1) {
                st.insert({i, j});
            }

            j = y-M;
            if(i >= 0 && j >=0 && grid[i][j]!=1) {
                st.insert({i, j});
            }

            int squares = st.size();
            for(auto par: st)
                q.push(par);

            if(squares & 1)
                odds++;
            else if(squares!=0 || (x==0 && y==0))
                evens++;
        }

        // for(int i=0; i<R; i++) {
        //     for(int j=0; j<C; j++) {
        //         cout << visited[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        cout << "Case " << i+1 << ": " << evens << ' ' << odds << '\n';
    }
     
    return 0;
}