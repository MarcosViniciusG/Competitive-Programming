#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> c(n);

    for(ll &i: c)
        cin >> i;

    map<ll, ll> mp;

    for(ll i=0; i<k; i++) 
        mp[c[i]]++;

    ll best = mp.size();

    for(ll i=1; i+k-1<n; i++) {
        mp[c[i-1]]--;
        if(mp[c[i-1]]==0)
            mp.erase(c[i-1]);
        
        mp[c[i+k-1]]++;
        ll a = mp.size();
        best = max(best, a);
    }
    
    cout << best << '\n';
    return 0;
}