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
        ll n, x;
        cin >> n >> x;

        vll a(n);
        for(ll &i: a)
            cin >> i;
        
        sort(a.begin(), a.end());

        vll team;
        ll ans=0;

        for(ll i=n-1; i>=0; i--) {
            team.push_back(a[i]);
            ll sz = team.size();
            if(team[sz-1] * sz >= x) {
                ans++;
                team.clear();
            }
        }

        cout << ans << "\n";
    }


    return 0;
}