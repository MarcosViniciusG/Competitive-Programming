#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
 
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, x, y, ai;
    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        map<ll, ll> a;
 
        ll soma=0;
        for(ll i=0; i<n; i++) {
            cin >> ai;
            soma += ai;
            a[ai]++;
        }

        ll counter=0;

        auto it1 = a.begin();
        while(it1!=a.end()) {
            // Lower and upper bound
            ll el = (*it1).first;
            ll qnt = (*it1).second;
            ll lb = soma - (y + el);
            ll ub = soma - (x + el);
 
            auto it = a.lower_bound(lb);

            // Too slow
            while((it != a.end()) && (*it).first <= ub) {
                if((*it).first != el)
                    counter += (qnt * (*it).second);
                else 
                    counter += (qnt * (qnt-1)) /2;
                it++;
            }
 
            a.erase(el);
            it1 = a.begin();
        }
 
        cout << counter << '\n';
    }
 
    return 0;
}