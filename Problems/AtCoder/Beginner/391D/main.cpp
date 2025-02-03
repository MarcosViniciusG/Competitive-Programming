#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, W, x, y;
    cin >> N >> W;
    set<ll> bottom_row;
    set<ll> bottom_row_pos;
    for(ll i=0; i<N; i++) {
        cin >> x >> y;
        x--; y--;
        if(!y && bottom_row_pos.find(x)==bottom_row_pos.end()) {
            bottom_row.insert(i);
            bottom_row_pos.insert(x);
        }
    }

    ll Q, t, a;
    cin >> Q;
    for(ll j=0; j<Q; j++) {
        cin >> t >> a;
    }

    return 0;
}