#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll st[2000][2000];

ll edit(const string& s, const string& t) {
    const ll c_i=1, c_r = 1, c_s = 1; // Costs
    ll m = s.length(), n = t.length();

    for(ll i=0; i<=m; i++)
        st[i][0] = i*c_r; 
    
    for(ll j=1; j<=n; j++)
        st[0][j] = j*c_i;

    for(ll i=1; i<=m; i++) {
        for(ll j=1; j<=n; j++) {
            ll insertion = st[i][j-1] + c_i;
            ll deletion = st[i-1][j] + c_r;
            ll change = st[i-1][j-1] + c_s*(s[i-1] == t[j-1] ? ll(0) : ll(1));
            st[i][j] = min({insertion, deletion, change});
        }
    }

    return st[m][n];
}

signed main() {
    string a, b;
    cin >> a >> b;
    cout << edit(a, b) << '\n';

    return 0;
}