#include <bits/stdc++.h>

using namespace std;

int dp[101][101];

int solve(vector<vector<int>> grid, int n, int ji, int je) {
    if(n==1) {
        return dp[ji][je] = grid[n-1][ji];
    }

    int soma=0;
    for(int j=ji; j<je; j++) {
        soma += grid[n-1][j];
    }

    if(dp[ji+1][je] == -1)
        dp[ji+1][je] = solve(grid, n-1, ji+1, je);
    if(dp[ji][je-1] == -1)
        dp[ji][je-1] = solve(grid, n-1, ji, je-1);

    return dp[ji][je] = soma + min(dp[ji+1][je], dp[ji][je-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, ni;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    vector<vector<int>> grid;
    int soma=0;

    for(int i=0; i<n; i++) {
        vector<int> v;
        for(int j=0; j<n; j++) {
            cin >> ni;
            v.push_back(ni);
        }
        grid.push_back(v);
    }

    cout << solve(grid, n, 0, n) << '\n';

    return 0;
}