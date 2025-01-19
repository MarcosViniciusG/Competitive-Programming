#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, m, card;

    cin >> t;
    while(t--) {
        cin >> n >> m;
        priority_queue<pll, vpll, greater<pll>> pq;
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<m; j++) {
                cin >> card;
                pq.push({card, i}); 
            }
        }

        vll order(n, -1);
        ll i=0;

        bool can = true;
        while(!pq.empty() && can) {
            pll par = pq.top(); pq.pop();
            if(order[i % n]!=-1 && order[i % n]!=par.second)
                can = false; 
            else if(order[i % n]==-1) {
                order[i % n] = par.second;
            }

            i++;
        }

        if(can) {
            for(auto e: order) {
                cout << e+1 << ' ';
            }
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }

    return 0;
}