#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    ll n;
    cin >> n;
    ll xi;
    map<ll, ll> mp;
    for(ll i=0; i<n; i++) {
        cin >> xi;
        mp[xi] = i;
    }

    ll rounds=1;
    ll prev = mp[1];
    for(ll i=2; i<=n ;i++) {
        if(mp[i] < prev) 
            rounds++;
        
        prev = mp[i];
    }

    cout << rounds << '\n';

    return 0;
}