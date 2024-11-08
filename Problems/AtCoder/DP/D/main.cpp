#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, W, wi, vi;
    cin >> n >> W;
    
    vector<ll> w;
    vector<ll> v;
    
    // No item (1 indexed)
    w.push_back(0);
    v.push_back(0); 

    for(int i=0; i<n; i++) {
        cin >> wi >> vi;
        w.push_back(wi);
        v.push_back(vi);
    }

    ll dp[n+1][W+1];

    // Empty sack
    for(int i=0; i<W+1; i++) {
        dp[0][i] = 0;
    }

    for(int i=1; i<(n+1); i++) {
        for(int j=0; j<(W+1); j++) {
            if(j - w[i] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}