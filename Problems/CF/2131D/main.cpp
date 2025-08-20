#include <bits/stdc++.h>
using namespace std;

#define dedinhos cin.tie(0)->sync_with_stdio(0)
using ll = long long;
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for(ll i = (a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (a); i >= (ll)(b); --i)
#define eb emplace_back

signed main() {
    dedinhos;
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vvll graph(n);
        ll a, b;
        rep(i, 0, n-1) {
            cin >> a >> b;
            a--; b--;
            graph[a].eb(b); graph[b].eb(a);
        }

        if(n==2) {
            cout << 0 << '\n';
            continue;
        }

        // discover the number of leaves in the tree
        // and subtract from the number of direct children
        // of the possible root i that are leaves
        int best_direct=0, direct=0, leaves=0;
        rep(i, 0, n) {  
            // if it's a leaf
            if(graph[i].size()==1) {
                leaves++;
                continue;
            }

            direct =0;
            for(auto v: graph[i]) {
                if(graph[v].size()==1)
                    direct++;
            } 

            best_direct = max(direct, best_direct);
        }

        cout << leaves - best_direct << '\n';
    }

    return 0;
}