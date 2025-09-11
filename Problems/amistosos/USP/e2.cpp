#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long
#define pll pair<ll, ll>
using oset = tree<ll, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

signed main() {
    ll n;
    cin >> n;
    vpll xs1;
    vpll xs2;
    ll ai, di;
    for(ll i=0; i<n; i++) {
        cin >> ai >> di;
        if(i < n/2)
            xs1.push_back({ai, di});
        else
            xs2.push_back({ai, di});
    }

    ll a1, a2, d1, d2;
    cin >> a1 >> d1 >> a2 >> d2;

    vpll v1, v2;
    rep(i, 0, 1 << xs1.size()) {
        ll a = 0, d = 0;
        rep(j, 0, xs1.size()) if (i & (1 << j))
            a += xs1[j].first, d += xs1[j].second;
        v1.eb(a, d);
    }

    rep(i, 0, 1 << xs2.size()) {
        ll a = 0, d = 0;
        rep(j, 0, xs2.size()) if (i & (1 << j))
            a += xs2[j].first, d += xs2[j].second;
        v2.eb(a, d);
    }

    sort(all(v1));
    sort(all(v2));
    
    ll N = v1.size(), M = v2.size();
    oset rb;
    ll ans = 0;

    ll l=M-1;
    ll r=M-1;
    rep(i, 0, N) {
        ll sum=v1[i].first;
        while(l >=0 && sum + v2[l].first >= a1) {
            rb.insert(v2[l].second);
            l--;
        }

        while(r >=0 && sum + v2[r].first > a2) {
            rb.erase(rb.upper_bound(v2[r].second));
            r--;
        }
        
        int idx1 = rb.order_of_key(d1-v1[i].second);
        int idx2 = rb.order_of_key(d2-v1[i].second+1);

        ans += idx2 - idx1;
    }

    cout << ans << '\n';
}