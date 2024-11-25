#include <bits/stdc++.h>

using namespace std;

int dir_x[] = {1, -1, -1, 1};
int dir_y[] = {1, -1, 1, -1};

char grid[101][101];
int H, W; 

int floodfill(int i, int j, char c1, char c2) {
    if(i < 0 || i >= H) return 0;
    if(j < 0 || j >= W) return 0;
    if(grid[i][j]!=c2) return 0;

    grid[i][j] = c1;

    int ans = 1;
    for(int d=0; d<4; d++)
        ans += floodfill(i + dir_y[d], j + dir_x[d], c1, c2);
    
    return ans;
}

signed main() {
    cin >> H >> W;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> grid[i][j];
        }
    }

    int S[min(H, W)] = {0};

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            int siz = floodfill(i, j, '.', '#');
            if(siz > 0) {
                siz /= 4;
                S[siz-1]++;
            }
        }
    }

    for(int i=0; i<min(H, W); i++) {
        cout << S[i] << ' ';
    }    
    cout << "\n";

    return 0;
}