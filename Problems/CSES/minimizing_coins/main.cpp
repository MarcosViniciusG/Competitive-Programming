#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;

    vll c(n, 0);
    for(ll &i: c) {
       cin >> i;
    }

    ll dp[x+1];
    dp[0] = 0;
    
    for(ll j=1; j<=x; j++) {
        dp[j] = 10000000;
        for(auto ci: c) {
            if(j - ci >= 0) {
                dp[j] = min(dp[j], dp[j-ci] + 1);
            }
        }
    }

    // for(auto e: dp)
    //     cout << e << " ";
    // cout << '\n';

    if(dp[x] != 10000000)
        cout << dp[x] << '\n';
    else
        cout << -1 << '\n';

    return 0;
}