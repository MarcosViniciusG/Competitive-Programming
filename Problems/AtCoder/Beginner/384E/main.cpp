#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using ppll = pair<ll ,pll>;

#define endl '\n';

ll dir_y[]={0, 0, 1, -1};
ll dir_x[]={1, -1, 0, 0};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll H, W, P, Q, X;
    cin >> H >> W >> P >> Q >> X;
    ll S[H][W];
    for(ll i=0; i<H; i++) {
        for(ll j=0; j<W; j++)
            cin >> S[i][j];
    }

    map<ll, pll> mp;
    set<pll> st;
    for(ll i=0; i<4; i++) {
        ll x = Q+dir_x[i];
        ll y = P + dir_y[i];
        st.insert({y, x});
    }

    return 0;
}