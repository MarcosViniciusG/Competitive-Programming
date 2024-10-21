#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 100;
int r, k, sum;
int dp[100][100][100];

int backtracking(int i, bool choosed[], int e, int sum)
{
    // Poda (PRUNING)
    if (e > k || sum > r)
        return 0;

    // Caso base: todos os elementos foram escolhidos
    if (i == r)
    {
        if (sum == r && e==k) return 1;
        else return 0;
    }

    if (dp[i][e][sum] != -1)
        return dp[i][e][sum];

    choosed[i] = false;
    ll with_i = backtracking(i + 1, choosed, e, sum);

    
    choosed[i] = true;
    ll without_i = backtracking(i + 1, choosed, e + 1, sum + i + 1);

    dp[i][e][sum] = with_i + without_i;
    return with_i + without_i;
}

int main()
{
    bool choosed[MAXN];

    cin >> r >> k;

    memset(dp, -1, sizeof(dp));

    backtracking(0, choosed, 0, 0);

    cout << backtracking(0, choosed, 0, 0) << endl;
    return 0;
}