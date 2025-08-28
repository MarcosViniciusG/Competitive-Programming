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

        pre.eb(1);
        ll i=1;
        ll v=1;
        while(v < ll(1e9)) {
            v*=3;
            pre.eb(v);
            i++;
        }
        i--;
        ll lm = i;

        coins.eb(3);
        for(ll j=1; j<i; j++) {
            coins.eb(pre[j+1] + j*pre[j-1]);
        }

        ll ans=0;
        vll deals(i+1, 0);
        ll num=0;
        i--;
        while(n > 0) {
            ll mx = (n / pre[i]);
            n -= mx * pre[i];
            ans += coins[i] * mx;
            deals[i] = mx;
            num += mx;
            if(pre[i] > n) 
                i--;
        }

        if(num > k) {
            cout << -1 << '\n';
            continue;
        }
        else if(num == k) {
            cout << ans << '\n';
            continue;
        }

        per(j, deals.size()-1, 1) {
            ll qnt = deals[j];
            if(qnt <= 0) continue;

            ll pos = (k - num) / 2;
            if(pos > qnt) {
                num += qnt * 2;
                deals[j] -= qnt;
                ans += coins[j-1] * qnt * 3;
                ans -= coins[j] * qnt;
                deals[j-1] += qnt*3; 
            }
            else if(pos <= qnt) {
                num += pos * 2;
                deals[j] -= pos;
                ans += coins[j-1] * pos * 3;
                ans -= coins[j] * pos;
                deals[j-1] += pos*3; 
                break;
            }

        }

        cout << ans << "\n";
    }

    return 0;
}