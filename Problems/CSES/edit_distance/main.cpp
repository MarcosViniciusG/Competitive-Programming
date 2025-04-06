#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())
#define rep(x, start, end) for(ll x=start; x<end; x++)


pair<ll, string> edit(const string&s, string &t) {
    ll ci=1, cr=1, cs=1, m=s.size(), n=t.size();
    vvll dp(m+1, vll(n+1)), pre=dp;

    rep(i, 0, m+1) dp[i][0] = i*cr, pre[i][0] = 'r';
    rep(j, 0, n+1) dp[0][j] = j*ci, pre[0][j] = 'i';
    rep(i, 1, m+1)
        rep(j, 1, n+1) {
            ll ins = dp[i][j-1] + ci, del = dp[i-1][j] + cr;
            ll subs = dp[i-1][j-1] + cs*(s[i-1] != t[j-1]);
            dp[i][j] = min({ins, del, subs});
            pre[i][j] = (dp[i][j] == ins ? 'i' : (dp[i][j] == del ? 'r' : 's'));
        }
    
    ll i = m, j = n;
    string ops;

    while(i || j) {
        if(pre[i][j] == 'i')
            ops += t[--j];
        else if(pre[i][j] == 'r') {
            ops += '-';
            i--;
        }
        else {
            --i, --j;
            if(s[i]==t[j]) ops += '=';
            else
                ops += ']', ops+= t[j], ops += ">-", ops += s[i], ops += "[";
        }
    }

    reverse(all(ops));
    return {dp[m][n], ops};
}

signed main() {
    fastio;
    string s, t;
    cin >> s >> t;

    pair<ll, string> res = edit(s, t);
    cout << res.first << '\n';

    return 0;
}