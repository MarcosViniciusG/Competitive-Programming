#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector <ll>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define endl '\n'
#define all(xs) xs.begin() , xs.end()
#define found(x, xs)(xs.find (x) != xs.end())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    map<ll ,ll> d;

    ll n, ai, ci;
    cin >> n;
    for(ll i=0; i<n; i++) {
        cin >> ai >> ci;
        if(found(ci, d)) 
            d[ci] = min(d[ci], ai);
        else 
            d[ci] = ai;
    }

    auto it = d.begin();
    ll best=0;
    while(it != d.end()) {
        best = max(best, (*it).second);
        it++;
    }

    cout << best << '\n';

    return 0;
}