#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vll odds;
        priority_queue<ll> pq;
        ll modd=0;
        ll meven=0;
        vll a(n);
        for(ll &i: a) {
            cin >> i;
            if(i & 1) {
                odds.push_back(i);
                modd = max(modd, i);
            }
            else {
                pq.push(i);
                meven = max(meven, i);
            }    
        }

        sort(odds.begin(), odds.end(), greater<ll>());

        ll e=0, o=1;
        ll mo = odds.size();
        ll soma=0;
        while(o<mo && !pq.empty()) {
            ll u = pq.top(); pq.pop();
            pq.push(odds[o] + u - 1); 
            o++;
        }

        if(modd > 0)
            while(!pq.empty()) {
                modd += pq.top(); pq.pop();
            }

        if(modd > 0)
            cout << modd << '\n';
        else if(!pq.empty())
            cout << pq.top() << '\n';
    }

    return 0;
}