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
    cin >> H >> W >> X >> P >> Q;
    P--; Q--;
    ll S[H][W];
    for(ll i=0; i<H; i++) {
        for(ll j=0; j<W; j++)
            cin >> S[i][j];
    }

    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
    pq.push({S[P][Q], {P, Q}});
    bool explored[501][501];
    memset(explored, false, sizeof(explored));

    ll str = 0;
    while(!pq.empty()) {
        pair<ll, pll> u = pq.top(); pq.pop();
        ll i = u.second.first;
        ll j = u.second.second;
        if(explored[i][j])
            continue;

        ll mx = str/X;
        if(mx !=0 && str % mx != 0)
            mx++;

        if(u.first >= mx && (i != P || j != Q))
            break;
        
        str += u.first;

        explored[i][j] = true;

        for(ll k=0; k<4; k++) {
            ll ni = i+dir_y[k]; ll nj = j+dir_x[k];
            if(ni >= H || ni < 0) continue;
            if(nj >= W || nj < 0) continue;
            if(explored[ni][nj]) continue;

            pq.push({
                S[ni][nj], 
                {ni, nj}}
            );
        }
    }

    cout << str << '\n';

    return 0;
}