#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ll m;
    cin >> m;
    string n;
    cin >> n;

    reverse(n.begin(), n.end());
    string ans="";
    ll c=1;
    for(ll i=0; i<m; i++) {
        ll res = (n[i] - '0') * 2;
        res += c;
        c = res / 10;
        ans += (res % 10) + '0';
    }

    if(c!=0) 
        ans += c + '0';

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    return 0;
}