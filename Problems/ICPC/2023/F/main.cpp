#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

signed main() {
    ll D, C, R;
    cin >> D >> C >> R;

    vll c(C);

    for(auto &i: c)
        cin >> i;

    vll r(R);
    ll ans=0;
    for(auto &i: r) {
        cin >> i;
        D += i;
        ans++;
    }

    for(ll i=0; i<C; i++) {
        if(D >= c[i]) {
            D -= c[i];
            ans++;
        }
        else
            break;
    }


    cout << ans << '\n';
    return 0;
}