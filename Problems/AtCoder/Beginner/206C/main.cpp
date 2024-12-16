#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;
    cin >> n;   
    vector<ll> a(n);

    for(ll &i: a)
        cin >> i;

    map<ll, ll> mp;
    for(auto e: a)
        mp[e]++;

    ll total = (n * (n-1)) / 2;
    for(auto par: mp) {
        total -= (par.second * (par.second-1))/2;
    }

    cout << total << '\n';
    return 0;
}