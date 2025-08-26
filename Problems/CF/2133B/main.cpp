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
        ll n;
        cin >> n;

        vll g(n);
        for(ll &i: g)
            cin >> i;

        // i need to sort and make the most
        // grumpy friends in pairs, the rest
        // will follow with friendship cost at 0
        
        // ok, this isn't the answer, but why?
        // i think i added more than necessary,
        // when n is odd

        sort(all(g), greater<ll>());
        ll ans=0;
        for(ll i=0; i+1<n; i+=2) 
            ans += max(g[i], g[i+1]);
        
        if(n & 1)
            ans += g[n-1];
        
        cout << ans << '\n';
    }


    return 0;
}