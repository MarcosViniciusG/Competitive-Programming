#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, m, L, li, ri, xi, vi;
    cin >> t;

    while(t--) {
        cin >> n >> m >> L;

        vpll positions;
        vll powerups;
        vll hurdles;

        for(ll i=0; i<n; i++) {
            cin >> li >> ri;

            hurdles.push_back(ri-li+1);
            positions.push_back(make_pair(li, 0));
        }

        for(ll i=0; i<m; i++) {
            cin >> xi >> vi;

            powerups.push_back(vi);
            positions.push_back(make_pair(xi, 1));
        }

        sort(positions.begin(), positions.end());

        ll k=1, no=0;
        priority_queue<ll> pq;
        for(ll i=0, p=0, h=0; i<(n+m); i++) {
            //cout << "POSIÇÃO: " << positions[i].first << '\n';
            if(positions[i].second) {
                //cout << "POWERUP :" << powerups[p] << '\n';
                pq.push(powerups[p]);
                p++;
            }  
            else {
                //cout << "OBSTÁCULO: " << hurdles[h] << '\n';
                if(k <= hurdles[h]) {
                    while(!pq.empty() && k<=hurdles[h]) {
                        k+=pq.top();
                        pq.pop();
                        no++;
                    }
                }

                if(k <= hurdles[h]) {
                    no=-1;
                    break;
                }
                h++;
            }
        }

        cout << no << '\n';
        
    }

    return 0;
}