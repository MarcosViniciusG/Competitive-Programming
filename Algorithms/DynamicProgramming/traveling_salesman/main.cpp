#include <bits/stdc++.h>
using namespace std;

int totalCost(int mask, int curr, int n, 
              vector<vector<int>> &cost, vector<vector<int>> &memo) {
    
    if (mask == (1 << n) - 1) {
        return cost[curr][0];
    }

    if (memo[curr][mask] != -1)
        return memo[curr][mask];

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
          
            ans = min(ans, cost[curr][i] + 
                      totalCost((mask | (1 << i)), i, n, cost, memo));
        }
    }

    return memo[curr][mask] = ans;
}
 
int tsp(vector<vector<int>> &cost) {
    int n = cost.size();
    vector<vector<int>> memo(n, vector<int>(1 << n, -1));
  
    return totalCost(1, 0, n, cost,
                     memo);  
}