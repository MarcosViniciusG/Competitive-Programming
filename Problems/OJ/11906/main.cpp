#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, R, C, M, N, W, xi, yi;
    cin >> T;
    while (T--)
    {
        cin >> R >> C >> M >> N;
        cin >> W;

        int grid[R][C] = {0};
        bool visited[R][C] = {false};

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
            int squares=0;
            for(i=x, moves=0; moves<M && i<R && grid[i][y]!=1; i++, moves++);
            
            if(moves==M && i<R) {
                for(j=y, moves=0; moves<N && j<R && grid[i][j]!=1; j++, moves++);  
                if(moves==N && j<C) {
                    squares++;
                    q.push({i, j});
                }

                for(j=y, moves=0; moves<N && j>=0 && grid[i][j]!=1; j--, moves++);  
                if(moves==N && j>=0) {
                    squares++;
                    q.push({i, j});
                }
            }

            for(i=x, moves=0; moves<M && i>=0 && grid[i][y]!=1; i--, moves++);
            
            if(moves==M && i>=0) {
                for(j=y, moves=0; moves<N && j<C && grid[i][j]!=1; j++, moves++);  
                if(moves==N && j<C) {
                    squares++;
                    q.push({i, j});
                }

                for(j=y, moves=0; moves<N && j>=0 && grid[i][j]!=1; j--, moves++);  
                if(moves==N && j>=0) {
                    squares++;
                    q.push({i, j});
                }
            }

            for(i=y, moves=0; moves<N && i<C && grid[x][i]!=1; i++, moves++);
            
            if(moves==N && i<C) {
                for(j=x, moves=0; moves<M && j<R && grid[j][i]!=1; j++, moves++);  
                if(moves==M && j<C) {
                    squares++;
                    q.push({j, i});
                }

                for(j=x, moves=0; moves<M && j>=0 && grid[j][i]!=1; j--, moves++);  
                if(moves==M && j>=0) {
                    squares++;
                    q.push({j, i});
                }
            }

            for(i=y, moves=0; moves<N && i>=0 && grid[x][i]!=1; i--, moves++);
            
            if(moves==N && i>=0) {
                for(j=x, moves=0; moves<M && j<R && grid[j][i]!=1; j++, moves++);  
                if(moves==M && j<C) {
                    squares++;
                    q.push({j, i});
                }

                for(j=x, moves=0; moves<M && j>=0 && grid[j][i]!=1; j--, moves++);  
                if(moves==M && j>=0) {
                    squares++;
                    q.push({j, i});
                }
            }

            if(squares!=0) {
                if(squares & 1)
                    odds++;
                else
                    evens++;
            }

            cout << x << ' ' << y << ' ' << squares << '\n';
        }

        cout << evens << ' ' << odds << '\n';
    }
     
    return 0;
}