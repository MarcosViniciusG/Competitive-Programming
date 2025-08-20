// ad-hoc greedy

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

        vll a(n);
        rep(i, 0, n)
            cin >> a[i];
        
        vll b(n);
        rep(i, 0, n)
            cin >> b[i];
        
        bool ok = true;
        if(b[n-1]!=a[n-1])
            ok = false;
        
        per(i, n-2, 0) {
            if((a[i] != b[i]) && ((a[i]^a[i+1])!=b[i]) && ((a[i]^b[i+1])!=b[i])) {
                ok = false;
                break;
            }
        }


        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}