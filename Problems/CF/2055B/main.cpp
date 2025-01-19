#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n;
    cin >> t;
    while(t--) {
        bool can=true;
        cin >> n;
        vll a(n);
        vll b(n);

        for(ll &i: a)
            cin >> i;

        for(ll &i: b)
            cin >> i;
        
        vll delta(n);
        ll negative_delta=0;
        for(ll i=0; i<n; i++) {
            delta[i] = a[i] - b[i];
            if(delta[i] < 0 && negative_delta==0) {
                negative_delta = delta[i];
            }
            else if(delta[i] < 0 && negative_delta!=0) {
                can = false;
                break;
            }
        }

        for(ll i=0; i<n && can; i++) {
            if((delta[i] >= 0) && (delta[i] + negative_delta < 0))
                can = false; 
        }


        cout << (can ? "YES" : "NO") << '\n';
    }

    return 0;
}