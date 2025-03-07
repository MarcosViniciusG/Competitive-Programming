#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n'
#define INF 10000000000

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll N, W, x, y;
    cin >> N >> W;
    vector<vpll> cols (W);
    vll d(N+1, 0);
    for(ll i=0; i<N; i++) {
        cin >> x >> y;
        x--; y--;
        cols[x].push_back({y, i}); // Store y coord with the ID of each block
    }

    ll blocks[N]; // Array to store y coord of each block
    for(ll i=0; i<W; i++) {
        sort(cols[i].begin(), cols[i].end()); // Sort all y coordinates in each col
        for(ll c=0; c<ll(cols[i].size()); c++) {
            blocks[cols[i][c].second] = c; // The block A is at the c-th pos in the col
            d[c] = max(d[c], cols[i][c].first); // Max y coordinate
        }
        d[ll(cols[i].size())] = INF; // If the column doesn't have more than C blocks
    }

    for(ll c=1; c<=N; c++) 
        d[c] = max(d[c], d[c-1] + 1); // Max between max coord and previous blocks

    ll Q, t, a;

    cin >> Q;
    for(ll j=0; j<Q; j++) {
        cin >> t >> a;
        a--;
        t--;
        if(t < d[blocks[a]])
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}