#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dp[1001][1001];
char grid[1001][1001];
int n;
ll m = ll(1e9 + 7);

bool ocupped(int i, int j) {
    return(grid[i][j]=='*');
}

int solve(int i, int j) {
    if(i==(n-1) && j==(n-1) && !ocupped(i, j))
        return dp[i][j] = 1;
    
    // cout << "Começa em " << i << " e " << j << '\n'; 
    // for(int k=i; k<n; k++) {
    //     for(int w=j; w<n; w++) {
    //         cout << grid[k][w];
    //     }
    //     cout << '\n';
    // }

    // Right
    if(((dp[i][j+1] == -1) && ((j+1) <= (n-1)))) {
        dp[i][j+1] = solve(i, j+1);
        dp[i][j+1] %= m; 
    }

    // Down
    if(((dp[i+1][j] == -1) && ((i+1) <= (n-1)))) {
        dp[i+1][j] = solve(i+1, j);
        dp[i+1][j] %= m;
    }

    if(ocupped(i, j))
        return dp[i][j] = 0;

    else if(j==(n-1))
        return dp[i][j] = dp[i+1][j];

    else if(i==(n-1))
        return dp[i][j] = dp[i][j+1];

    else
        return dp[i][j] = (dp[i][j+1] + dp[i+1][j]) % m;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) { 
        for(int j=0; j<n; j++) 
            cin >> grid[i][j];
        
        cin.ignore(1, '\n');
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << '\n';

    return 0;
}