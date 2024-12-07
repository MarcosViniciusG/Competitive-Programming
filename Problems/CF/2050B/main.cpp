#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, ai;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> a;
        for(ll i=0; i<n; i++) {
            cin >> ai;
            a.push_back(ai);
        }
    
        ll sum1=0;
        ll sum2=0;
        ll c1=0;
        ll c2=0;

        for(ll i=0; i<n; i++) {
            if(i & 1) {
                sum2 += a[i];
                c2++;
            }
            else {
                sum1 += a[i];
                c1++;
            }
        }

        if((sum1 % c1==0) && (sum2 % c2==0) && (sum1/c1 == sum2/c2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}