#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;

    ll ans=0;
    for(ll i=0; i<ll(s.length()); i++) {
        if(s[i]=='0') {
            ll j=i+1;
            ll counter=1;
            while(j<ll(s.length()) && s[i]==s[j]) {
                counter++;
                j++;
            }

            if(counter & 1)
                ans += (counter/2) + 1;
            else
                ans += (counter/2);
            
            i = j-1;
        }
        else
            ans++;
    }

    cout << ans << '\n';
    return 0;
}