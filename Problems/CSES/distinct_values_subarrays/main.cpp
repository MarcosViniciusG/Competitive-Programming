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
    ll n;
    cin >> n;

    ll ans=0;
    vll a(n);
    rep(i, 0, n) 
        cin >> a[i];

    ll l=0;
    set<ll> st;
    ll r=0;
    for(; r<n; r++) {
        ll rn = l;
        while(st.find(a[r])!=st.end() && l < r) {
            st.erase(a[l]);
            l++;
        }

        if(l > rn) {
            rn--;
            ans--;
        }
        ans += (l - rn + 1) * (l-rn) / 2;
        cout << ans << "\n";
        st.insert(a[r]);
    }
    cout << ans + (((r-l+1) * (r-l)) / 2) << '\n';
    return 0;
}