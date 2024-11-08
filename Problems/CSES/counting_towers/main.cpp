#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 100000;
ll dp[MAXN];
ll m = ll(1e9 + 7);

ll solve(ll n) {
    if(n==1)
        return dp[n] = 2;

    if(dp[n-1]==-1)
        dp[n-1] = solve(n-1);

    return dp[n] = (5*(dp[n-1] - 1) % m) + (ll(1 << n) % m);
}

int main() {
    memset(dp, -1, sizeof(dp));
    solve(MAXN-1);

    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}