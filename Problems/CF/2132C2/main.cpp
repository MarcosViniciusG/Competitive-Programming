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
    // dedinhos;
    ll t;
    cin >>t;
    while(t--) {
        ll n, k;
        cin >> n >> k;

        vll pre;
        vll coins;

        pre.push_back(1);
        ll i=1;
        ll v=1;
        while(v < ll(1e9)) {
            v*=3;
            pre.push_back(v);
            i++;
        }
        i--;

        coins.push_back(3);
        for(ll j=1; j<i; j++) {
            coins.push_back(pre[j+1] + j*pre[j-1]);
        }

        ll ans=0;
        queue<ll> deals;
        while(n > 0) {
            while(pre[i] <= n) {
                deals.push(i);
                n -= pre[i];
                ans += coins[i];
            }
            if(pre[i]>n)
                i--;
        }

        if(deals.size() > k) {
            cout << -1 << '\n';
            continue;
        }
        else if(deals.size() == k) {
            cout << ans << '\n';
            continue;
        }

        ll num = deals.size();
        while(num + 2 <= k && !deals.empty()) {
            ll u = deals.front(); deals.pop();
            if(u==0)
                break;
            
            ll temp = 3;
            ll off=1;
            while(u > 0 && num + off) {
                num += 2;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}