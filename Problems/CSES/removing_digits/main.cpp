#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll dp[n+1];
    dp[0] = 0;
    vector<ll> digits;

    for(ll i=1; i<=n; i++) {
        ll nu = i;
        
        while (nu > 0)
        {
            digits.push_back(nu%10);
            nu /= 10;
        }
        
        ll best= ll(INFINITY);
        for(auto d: digits) {
            if(d && i - d >= 0)
                best = min(best, dp[i-d]);
        }

        dp[i] = best+1;
        digits.clear();
    }

    cout << dp[n] << '\n';

    return 0;
}