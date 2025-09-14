// O(n)
// monotonic stack (smaller and greater previous element) and partial sum

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
    ll n;
    cin >> n;
    vll a(n);
    vll ans(n);
    stack<pll> st;

    vll pse(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        
        while(!st.empty() && st.top().first >= a[i])
            st.pop();
        
        pse[i] = (st.empty() ? 0 : st.top().second+1);
        
        st.push({a[i], i});
    }

    vll nse(n);
    while(!st.empty()) st.pop();

    for(ll i=n-1; i>=0; i--) {        
        while(!st.empty() && st.top().first >= a[i])
            st.pop();
        
        nse[i] = (st.empty() ? n-1 : st.top().second);
        
        st.push({a[i], i-1});
    }

    // for(auto e: pse)
    //     cout << e << ' ';
    // cout << '\n';

    // for(auto e: nse)
    //     cout << e << ' ';
    // cout << '\n';

    for(ll i=0; i<n; i++) {
        ll sz = nse[i] - pse[i];
        ans[sz] = max(ans[sz], a[i]);
        // cout << sz << ' ';
    }
    // cout << "\n";

    ll mx=0;
    for(ll i=n-1; i>=0; i--) {
        mx = max(mx, ans[i]);
        ans[i] = mx;
    }

    for(auto e: ans)
        cout << e << ' ';

    cout << '\n';
    return 0;
}