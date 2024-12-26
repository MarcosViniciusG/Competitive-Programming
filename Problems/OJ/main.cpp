#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll T, R, C, M, N, W, xi, yi;
    cin >> T;

    while(T--) {
        cin >> R >> C >> M >> N >> W;
        vll dirx = {-1, 1};
        vll diry = {-1, 1};
        vll moves = {M, N};
        sort(moves.begin(), moves.end());   

        ll graph[R][C];
        memset(graph, 0, sizeof(graph));

        for(ll i=0; i<W; i++) {
            
        }
        
        for(ll i=0; i<M; i++) {
            for(ll j=0; j<N; j++) {

            }
        }
    }

    return 0;
}