#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    int grid[n][n];
    int soma=0;

    for(int i=0; i<n; i++) 
    for(int j=0; j<n; j++) {
        cin >> grid[i][j];
        if(i+1==n)
            soma += grid[i][j];
    }

    int dp[n+1][n+1];
    for(int i=0; i<n+1; i++) {
        dp[n][i] = soma; 
    }


    return 0;
}