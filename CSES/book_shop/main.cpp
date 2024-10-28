#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n);
    vector<int> s(n);

    for(int &i: h)
        cin >> i;
    
    for(int &i: s)
        cin >> i;

    int dp[x+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++) {
        // j >= h[i] prevents (j-h[i] < 0)
        for(int j=x; j>=h[i]; j--) 
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
    }

    cout << dp[x] << '\n'; 

    return 0;
}