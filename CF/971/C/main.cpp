#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(ll x, ll y, ll k) {
    ll xm = ceil(1.0* x / k);
    ll ym = ceil(1.0*y / k);

    ll diff = ym-xm;
    if(diff < 0)
        xm--;

    return xm + ym + abs(diff);
}

int main() {
    ll t, x, y, k;
    cin >> t;
    while (t--)
    {
        cin >> x >> y >> k;
        cout << solve(x, y, k) << endl;
    }
    
    return 0;
}