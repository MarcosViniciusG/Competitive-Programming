#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

vll xs;
ll n;

signed main() {
    cin >> n;

    ll xi;
    for(ll i=0; i<n; i++) {
        cin >> xi; 
        xs.push_back(xi);
    }
    sort(all(xs));
    
    ll val=1;
    for(ll i=0; i<n; i++) {
        if(xs[i] > val) {
            cout << val << '\n';
            return 0;
        }
        else
            val += xs[i];
    }

    cout << val << "\n";


    return 0;
}