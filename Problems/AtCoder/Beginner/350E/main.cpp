#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

double dp[64][64][64];

ll N, A, X, Y;

void decomp(const ll i, ll &first, ll &second, ll &third) {
    if(i==2) {
        first = 1;
    }
    else if(i==3) {
        second = 1;
    } 
    else if(i==4) {
        first = 2;
    }
    else if(i==5) {
        third = 1;
    }
    else if(i==6) {
        first = 1;
        second = 1;
    }
    return;
}

double solve(ll x, ll p2, ll p3, ll p5) {
    if(x==0) 
        return dp[p2][p3][p5] = 0;

    ll first=0, second=0, third=0;
    decomp(A, first, second, third);
    if(dp[p2+first][p3+second][p5+third]==-1)
        dp[p2+first][p3+second][p5+third] = solve(floor(x/A), p2+first, p3+second, p5+third);

    double op1 = X + dp[p2+first][p3+second][p5+third];
    double op2 = (6.0/5.0) * Y;
    double total = 0;
    for(ll i=2; i<=6; i++) {
        first=0; second=0; third=0;
        decomp(i, first, second, third);
        if(dp[p2+first][p3+second][p5+third]==-1)
            dp[p2+first][p3+second][p5+third] = solve(floor(x/i), p2+first, p3+second, p5+third);
        
        total += dp[p2+first][p3+second][p5+third]; 
    }

    op2 += (1.0/5.0)*total;

    return dp[p2][p3][p5] = min(op1, op2);
}

signed main() {
    fastio;
    cin >> N >> A >> X >> Y;
    for(ll i=0; i<64; i++)
    for(ll j=0; j<64; j++)
    for(ll k=0; k<64; k++)
        dp[i][j][k] = -1;

    printf("%.15lf\n", solve(N, 0, 0, 0));
    return 0;
}