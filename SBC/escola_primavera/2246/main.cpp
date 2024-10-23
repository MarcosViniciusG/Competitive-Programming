#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    ll V, M;
    cin >> V >> M;

    vll v(M, 0);

    ll soma=0;
    for(ll &i: v) {
        cin >> i;
        soma += i;
    }

            // Time complexity: O(nV) Space complexity: O(nV)

    // bool dp[M+1][V+1];
    // for(ll i=0; i<=V; i++) {
    //     dp[0][i] = 0;
    // }

    // for(ll i=0; i<=M; i++) {
    //     dp[i][0] = 1;
    // }

    // for(ll i=1; i<=M; i++) {
    //     for(ll j=1; j<=V; j++) {
    //         dp[i][j] = dp[i-1][j] | 
    //                     ((j-v[i-1] >= 0) && dp[i-1][j-v[i-1]]);
    //     }
    // }

            // DEBUG
            
    // for(int i=0; i<=soma; i++) {
    //     cout << i << " ";
    // }
    // cout << '\n';

    // for(int i=0; i<=M; i++) {
    //     for(int j=0; j<=soma; j++) {
    //         cout << dp[i][j] << " ";
    //         if(j >= 10)
    //             cout << " ";  
    //     }
    //     cout << '\n';
    // }

            // Time complexity: O(nV) Space complexity: O(2*n) == O(n)

    vector<bool> prev(V + 1, false), curr(V + 1);
    prev[0] = true;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= V; j++) {
            if (j < v[i - 1])
                curr[j] = prev[j];
            else
                curr[j] = (prev[j] || prev[j - v[i - 1]]);
        }
        prev = curr;
    }

    if((V <= soma) && (prev[V]))
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}