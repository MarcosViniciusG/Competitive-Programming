#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[m][n];
        dp[0][0] = grid[0][0];

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                int sum1 = grid[i-1][j] + dp[i][j-1];
                int sum2 = grid[i][j-1] + dp[i][j-1];

                dp[i][j] = min(sum1, sum2) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};

int main() {
    int m, n, e;

    cin >> m >> n;

    vector<vector<int>> grid;
    for(int i=0; i<m; i++) {
        vector<int> row;

        for(int j=0; j<n; j++) {
            cin >> e;
            row.push_back(e);
        }

        grid.push_back(row);
    }

        // Debug
    for(int i=0; i<m; i++) {
        
        for(int j=0; j<n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    Solution sol;
    cout << sol.minPathSum(grid) << endl;

    return 0;
}