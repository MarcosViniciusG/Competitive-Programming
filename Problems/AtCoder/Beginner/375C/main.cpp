#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    char grid[N][N];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> grid[i][j];
        }
    }

    char ans[N][N];

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            // Number of times that the op will be repeated
            // After fours times, it repeats
            int c = min({i+1, j+1, N-i, N-j}) % 4;
            if(c==0)
                ans[i][j] = grid[i][j];
            else if(c==1)
                ans[j][N-i-1] = grid[i][j];
            else if(c==2)
                ans[N-1-i][N-j-1] = grid[i][j];
            else if(c==3)
                ans[N-j-1][i] = grid[i][j];
        }
    }

    for(int j=0; j<N; j++) {
        for(int k=0; k<N; k++) {
            cout << ans[j][k];
        }
        cout << endl;
    }

    return 0;
}