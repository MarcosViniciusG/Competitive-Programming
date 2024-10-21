#include <bits/stdc++.h>

using namespace std;

int dp[110][10100];

bool subsetSum(int a[], int n, int sum) {
    if(sum==0)
        return true;
    if(n==0)
        return false;

    if(dp[n-1][sum] != -1)
        return dp[n-1][sum];
    
    if(a[n-1] > sum)
        return dp[n-1][sum] = subsetSum(a, n-1, sum);
    
    else {
        return dp[n-1][sum] = subsetSum(a, n-1, sum) || 
            subsetSum(a, n-1, sum-a[n-1]);
    }
}

int main() {
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    if(n & 1) {
        cout << -1 << endl;
        return 0;
    }

    

    return 0;
}