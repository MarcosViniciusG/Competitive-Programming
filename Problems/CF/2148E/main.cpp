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
    dedinhos;
    ll t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;

        vll counter(n+1, 0);
        vll a(n);
        rep(i, 0, n) {
            cin >> a[i];
            counter[a[i]]++;
        }

        ll l=0;
        ll ans=0;
        vll temp_counter(n+1, 0);
        rep(r, 0, n) {
            temp_counter[a[r]]++;
            while(l-1 < r && (counter[a[r]] - temp_counter[a[r]]) % k !=0) {
                temp_counter[a[l]]--;
                l++;
            }

            if((counter[a[r]] - temp_counter[a[r]]) % k ==0)
                ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}