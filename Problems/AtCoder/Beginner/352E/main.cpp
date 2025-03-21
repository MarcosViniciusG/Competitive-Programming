#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

#define MAXN ll(2*1e6 + 1LL)

vpll graph[MAXN];

signed main() {
    fastio;
    ll N, M;
    cin >> N >> M;

    ll K, C, A;
    for(ll i=0; i<M; i++) {
        cin >> K >> C;
        vll S(K);
        for(ll j=0; j<K; j++) { 
            cin >> S[j];
            S[j]--;
        }
        
        for(ll j=0; j<K; j++) {
            for(ll k=j+1; k<K; k++) {
                graph[S[j]].push_back({S[k], C});
                graph[S[k]].push_back({S[j], C});
            }
        }
    }

    ll cost=0;
    vll tree(N);
    vpll result[N];

    

    return 0;
}