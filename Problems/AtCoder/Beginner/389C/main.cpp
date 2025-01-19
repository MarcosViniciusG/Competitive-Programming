#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll q, qi, k;
    cin >> q;
    vector<pll> pos;
    ll delta=0, delta_pos=0;
    ll ls=0;
    ll hc=0;
    while(q--) {
        cin >> qi;
        if(qi!=2)
            cin >> k;

        if(qi==1) {
            ll coords=0;
            coords += ls + hc;

            // Length and coords
            pos.push_back({k, coords});

            ls = k;
            hc = coords;
        }
        else if(qi==2) {
            delta += pos[delta_pos].first;
            delta_pos++;
        }
        else if(qi==3) {
            cout << pos[k-1 + delta_pos].second - delta << '\n';
        }

    }


    return 0;
}