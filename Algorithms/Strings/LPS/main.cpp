#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2000;
ll st[N][N]; 

ll dp(const string& s, ll i, ll j)
{
    if (i > j)
        return 0;
    
    if(i==j)
        return 1;

    if(st[i][j] != -1)
        return st[i][j]; 

    st[i][j] = max(dp(s, i + 1, j), dp(s, i, j - 1));

    if(s[i] == s[j])
        st[i][j] = max(st[i][j], dp(s, i+1, j-1) + 2);

    return st[i][j];
}

signed main() {
    memset(st, -1, sizeof(st));

    string s;
    cin >> s;
    ll n = s.length();
    cout << dp(s, 0, n-1) << '\n';

    return 0;
}