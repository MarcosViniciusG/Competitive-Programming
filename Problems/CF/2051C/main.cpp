#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, m, k, qi;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        vll a(m);
        set<ll> q;

        for(ll &i: a)
            cin >> i;

        for(ll i=0; i<k; i++) {
            cin >> qi;
            q.insert(qi);
        }

        string ans="";

        if(k!=n) {
            for(ll i=0; i<m; i++)
                ans += '0';
        }
        else {
            for(ll i=0; i<m; i++) 
                ans += '1';
        }

        if(k==(n-1)) {
            for(ll i=0; i<m; i++) {
                if(q.find(a[i]) == q.end())
                    ans[i] = '1';
            }
        }

        cout << ans << '\n';
    }

    return 0;
}