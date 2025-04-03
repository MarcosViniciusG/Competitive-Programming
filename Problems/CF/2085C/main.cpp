#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

// 010
// 101

// 1001
// 0110

// 0101
// 1000

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;

    while(t--) {
        ll x, y;
        cin >> x >> y;
        if(x==y) {
            cout << -1 << '\n';
            continue;
        }
        
        for(ll i=0; i<64; i++) {
            ll k = (1<<i) - max(x, y);
            if(k >= 0 && (x+y+2*k==((x+k)^(y+k)))){
                cout << k << '\n';
                break;   
            }
        }      
    }

    return 0;
}