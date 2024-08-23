#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200002;

int main() {
    int t, l, r;
    cin >> t;

    int lg[MAXN+1];
    lg[0] = 0;
    lg[1] = 0;
    lg[2] = 0;
    for(int i=3; i<=MAXN; i++) {
        lg[i] = lg[i/3] + 1; 
    }
    
    int dp[MAXN+1];
    dp[0] = 0; // 2
    for(int i=1; i<=MAXN; i++) {
        dp[i] = (dp[i-1] + lg[i] + 1); // 3 (i==1) // 5 (i==2)
    }

    while(t--) {
        cin >> l >> r;

        cout << lg[l] + 1 + (dp[r] - dp[l-1]) << endl;
    }

}