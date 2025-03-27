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
        ll n;
        cin >> n;

        vll ans;
        for(ll i=1; i<=n; i+=2)
            ans.push_back(i);
        
        for(ll i=2; i<=n; i+=2)
            ans.push_back(i);

        if(n%2==0)
            cout << -1 << "\n";
        else {
            for(auto e: ans)
                cout << e << ' ';
            cout << "\n";
        }
    }

    return 0;
}