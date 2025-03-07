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
    for(ll i=0; i<n; i++) 
        cin >> a[i];

    for(ll i=1; i<n-1; i++)
        can = can && (a[i]*a[i] == a[i-1] * a[i+1]);

    cout << (can ? "Yes" : "No") << '\n';

    return 0;
}