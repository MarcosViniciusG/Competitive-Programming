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

    char grid_cp[N][N];

    for(int i=0; i<(N/2); i++) {

        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                grid_cp[j][k] = grid[j][k];
            }
        }

        for(int j=i; j<(N-i); j++) {
            for(int k=i; k<(N-i); k++) {
                grid_cp[k][N-j-1] = grid[j][k]; 
            }
        }
        
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                grid[j][k] = grid_cp[j][k];
            }
        }

    }

    for(int j=0; j<N; j++) {
        for(int k=0; k<N; k++) {
            cout << grid[j][k];
        }
        cout << endl;
    }

    return 0;
}