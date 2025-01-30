#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;
    cin >> n;
    ll a[n];

    bool can = true;
    double ratio;
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        if(i==1) {
            ratio = a[1] / double(a[0]);
        }
        else if(i>1 && ratio != a[i]) 
            can = false;
    }

    cout << (can ? "Yes" : "No") << '\n';
    return 0;
}