#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, k, ai, bi;
    cin >> t;
    while(t--) {
        cin >> n >> k;

        priority_queue<pll> pq;
        vll tempa(n);
        vll tempb(n);
        for(ll i=0; i<n; i++) {
            cin >> ai;
            tempa[i] = -ai;
        }

        for(ll i=0; i<n; i++) {
            cin >> bi;
            tempb[i] = -bi;
        }

        for(ll i=0; i<n; i++) {
            pq.push({tempa[i], tempb[i]});
        }

        ll earnings=0;
        ll last_price=0;
        ll possible_earnings=0;
        ll best=0;
        ll unsatified=0;
        ll qnt=n;
        ll buying=0;

        multiset<ll> b;
        while(!pq.empty()) {
            pll u = pq.top(); pq.pop();
            if((-u.first) > last_price) {
                auto it = b.begin();
                while(it!=b.end() && (*it) < (-u.first)) {
                    b.erase(*it);
                    it = b.begin();
                    unsatified--;
                    qnt--;
                }
                unsatified += buying;
                buying = 1;
                last_price = (-u.first);
            }

            buying++;
            b.insert(-u.second);
            earnings = (qnt * last_price);

            if(unsatified <= k)
                best = max(earnings, best);
        }

        cout << best << '\n';
    }

    return 0;
}