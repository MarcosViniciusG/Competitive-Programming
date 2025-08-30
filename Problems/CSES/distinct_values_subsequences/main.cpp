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

const ll m = ll(1e9) + 7;

signed main() {
    ll n;
    cin >> n;

    vll a(n);
    rep(i, 0, n) 
        cin >> a[i];

    set<ll> st;
    vll pre(n+1, 0);
    pre[0] = 0;
    cout << pre[0] << ' ';
    rep(i, 0, n) {
        st.insert(a[i]);
        pre[i+1] = st.size();
        cout << pre[i+1] << ' ';
    }
    cout << '\n';

    ll ans=0;
    rep(i, 0, n) {
        ll l = pre[n] - pre[i];
        ans += ((l * (l+1)) % m / 2) % m;
        ans %= m;
    }
    cout << ans % m << '\n';
    return 0;
}