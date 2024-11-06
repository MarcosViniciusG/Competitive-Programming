#include <bits/stdc++.h>

using namespace std;
using triple = tuple<int, int, int>;


signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    int n, k, si, fi, ci;
    cin >> n >> k;

    vector<triple> queijos;

    for(int i=0; i<n; i++) {
        cin >> si >> fi >> ci;
        triple t = {fi, si, ci};
        queijos.push_back(t);
    }

    sort(queijos.begin(), queijos.end());

    // cout << "DEBUG: \n";
    // for(auto tri: queijos) {
    //     cout << get<1>(tri) 
    //     << ' ' << get<0>(tri) 
    //     << ' ' << get<2>(tri) << '\n';
    // }

    int dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= get<2>(queijos[i-1])) {
                for(int w=i-1; w>=1; w--) {
                    if(dp[w-1][1] <= get<1>(queijos[i-1])) {
                        dp[i][j] = max(dp[i][j], dp[w][j-get<2>(queijos[i-1])]+1);
                    }
                }
            }
        }
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=k; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }

    cout << dp[n][k] << '\n';

    return 0;
}