#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k;
    string s, t;
    cin >> k >> s >> t;
    ll n = s.length();
    ll m = t.length();

    ll diff=0;
    ll j=0;

    if(abs(n-m) > 1)
        diff=2;

    for(ll i=0; i<n && j<m; i++, j++) {
        if(s[i] != t[j]) { 
            diff++;

            if(n < m)
                j++;
            else if(n > m)
                i++;
            
            if(abs(i-j)==1 && s[i]!=t[j])
                diff++;
        }
    }

    cout << (diff<=1 ? "Yes" : "No") << '\n';

    return 0;
}