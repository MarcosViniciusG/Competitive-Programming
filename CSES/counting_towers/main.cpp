#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 10000;
ll dp[MAXN][3];
ll m = ll(1e9 + 7);

ll solve(ll n, ll c) {
    if(n==1 && c==1)
        return dp[1][1] = 1;
    else if(n==1 && c==2)  
        return dp[1][2] = 2;
    else if(c==1) {
        if(dp[n-1][c]==-1)
            dp[n-1][c] = solve(n-1, c);

        dp[n][c] = (dp[n-1][c] * 2);
        dp[n][c] %= m;
        return dp[n][c];
    }

    dp[n][c-1] = solve(n, c-1);
    dp[n-1][c] = solve(n-1, c);

    return dp[n][c] = 4*dp[n-1][c] + 2*(dp[n][c-1]) % m;
}


int main() {
    memset(dp, -1, sizeof(dp));
    solve(MAXN-1, 2);

    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n][2] << '\n';
    }

    return 0;
}