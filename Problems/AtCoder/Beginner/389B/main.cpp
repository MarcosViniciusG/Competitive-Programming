#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll x;
    cin >> x;

    ll i=1;
    ll prod=1;
    for(i=1, prod=1; prod<=x; i++, prod*=i) {
        if(prod==x)
            break;
    }

    cout << i << '\n';
    return 0;
}