// O(n)

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;
using vvpll = vector<vpll>;

#define rep(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define per(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define all(xs) xs.begin(), xs.end()

signed main() {
    ll n, k;
    cin >> n >> k;

    vll a(n);
    ll menor_idx=-1;
    ll menor=-1;
    rep(i, 0, n) {
        cin >> a[i];
        if(!i || a[i] < menor) {
            menor = a[i];
            menor_idx = i;
        }
    }

    ll ans=menor+k;
    ll idx=menor_idx;
    rep(i, menor_idx+1, menor_idx+k) {
        if(i >= n)
            break;
        
        ll off = k - (i - menor_idx);
        if(menor + off > a[i])
            idx = i;
    }

    per(i, n-1, 0) {
        if(i <= idx)
            a[i] += max(k - (idx - i),0LL);
        
        ans = min(ans, a[i]);
    }

    cout << ans << '\n';

    return 0;
}