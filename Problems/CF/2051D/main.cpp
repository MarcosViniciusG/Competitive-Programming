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
        for(auto par: a) {
            // Lower and upper bound
            ll el = par.first;
            ll qnt = par.second;
    
            auto it = a.lower_bound();
            while((it != a.end()) && (soma - (*it).first-el) <= y && (soma -((*it).first+el)) >= x) {
                if((*it).first != el)
                    counter += (qnt * (*it).second);
                else
                    counter += (qnt-1);
                it++;
            }

            a[el] = 0;
        }

        cout << counter << '\n';
    }

    return 0;
}