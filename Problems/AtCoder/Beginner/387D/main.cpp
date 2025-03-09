#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

char grid[1001][1001];

int H, W;
#define INF ll(1e9)

ll sol = INF;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> H >> W;

    ll starti, startj;
    ll goali, goalj;
    for(ll i=0; i<H; i++) {
        for(ll j=0; j<W; j++) {
            cin >> grid[i][j];
            if(grid[i][j]=='S') {
                starti = i;
                startj = j;
            }
            else if(grid[i][j]=='G') {
                goali = i;
                goalj = j;
            }
        }
    }


    queue<pll> q;
    bool horizontal;
    ll dp[1001][1001];

    for(ll k=0; k<2; k++) {
        for(ll i=0; i<1001; i++) 
        for(ll j=0; j<1001; j++)
            dp[i][j] = INF;

        horizontal = k; 
        q.push({starti, startj});
        dp[starti][startj] = 0;

        // BFS to find shortest path to the goal
        while (!q.empty())
        {
            pll u = q.front(); q.pop();
            ll i = u.first;
            ll j = u.second;

            if(horizontal && !(dp[i][j] & 1) || (!horizontal && (dp[i][j] & 1))) {
                if((j+1 < W) && (grid[i][j+1] != '#') && (dp[i][j+1]==INF)) {
                    dp[i][j+1] = dp[i][j] + 1;
                    q.push({i, j+1});
                }

                if((j-1 >= 0) && (grid[i][j-1] != '#') && (dp[i][j-1]==INF)) {
                    dp[i][j-1] = dp[i][j] + 1;
                    q.push({i, j-1});
                }
            }
            else {
                if((i+1 < H) && (grid[i+1][j] != '#') && (dp[i+1][j]==INF)) {
                    dp[i+1][j] = dp[i][j] + 1;
                    q.push({i+1, j});
                }

                if((i-1 >= 0) && (grid[i-1][j] != '#') && (dp[i-1][j]==INF)) {
                    dp[i-1][j] = dp[i][j] + 1;
                    q.push({i-1, j});
                }
            }
        }
        sol = min(sol, dp[goali][goalj]);
    }

    cout << (sol==INF ? -1 : sol) << '\n';

    return 0;
}