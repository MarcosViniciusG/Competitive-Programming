#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vll h(n);
    for(ll &i: h)
        cin >> i;

    ll seq=1;
    ll best=1;
    for(ll jump=1; jump<n; jump++) {
        for(ll i=0; i<n; i++) {
            for(ll j=i+jump; j<n && h[i]==h[j]; j+=jump) {
                seq++;
            }
            best = max(best, seq);
            seq=1;
        }
    }

    cout << best << '\n';

    return 0;
}