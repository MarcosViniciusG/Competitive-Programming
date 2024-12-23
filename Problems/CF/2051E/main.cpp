#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;

        priority_queue<pll, vpll, greater<pll>> pq;
        vll tempa(n);
        vll tempb(n);
    
        for(ll &i: tempa)
            cin >> i;

        for(ll &i: tempb)
            cin >> i;

        for(ll i=0; i<n; i++)
            pq.push({tempa[i], 1});

        for(ll i=0; i<n; i++) 
            pq.push({tempb[i], 2});

        ll trees=n;
        ll last_price=0;
        ll unsatisifed=0;
        ll best=0;

        priority_queue<pll, vpll, greater<pll>> last_customers;
        while(!pq.empty()) {
            pll par = pq.top(); pq.pop();
            ll price = par.first;
            ll tipo = par.second;
            if(price > last_price) {
                while(!last_customers.empty()) {
                    pll last_customer = last_customers.top(); last_customers.pop();
                    ll last_customer_tipo = last_customer.second;
                    if(last_customer_tipo==1)
                        unsatisifed++;
                    else {
                        unsatisifed--;
                        trees--;
                    }
                }

            }

            if(unsatisifed <= k)
                best = max(best, trees*price);
            last_price = price;
            last_customers.push(par);
        }

        cout << best << '\n';
    }

    return 0;
}