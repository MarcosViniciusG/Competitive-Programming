#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

char grid[1001][1001];
int dp[1001][1001][2] = {-1};

int H, W;

int solve(int i, int j, bool horizontal) {
    if(grid[i][j]=='G')

    if(horizontal) {
        if((j+1 < W) && dp[i][j+1]==-1)
            dp[i][j+1] = 1 + solve(i, j+1, false);
        if((j-1 >= 0) && dp[i][j-1]==-1)
            dp[i][j-1] = 1 + solve(i, j-1, false); 
    }
    else {
        solve(i+1, j, true);
        solve(i-1, j, true);
    }

    if(horizontal)
    {
        if((j+1 < W) && (j-1 >=0))
            return min(dp[i][j+1], dp[i][j-1]);
        else if(j+1<W)
            return dp[i][j+1];
        else if(j-1>=0)

    }
        return min(dp[i])
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    return 0;
}