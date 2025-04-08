#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        ll n = s.size();
        ll idx;
        for(ll i=n-1; i>=0; i--) {
            if(s[i] != '0') {
                idx = i;
                break; 
            }
        }

        ll ans = n - idx - 1;  

        for(ll i=0; i<idx; i++)
            if(s[i]!='0')
                ans++;

        cout << ans << '\n';
    }

    return 0;
}