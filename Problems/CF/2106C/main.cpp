#include <bits/stdc++.h>
using namespace std;

using ll =            long long;
#define vll           vector<ll>
#define vvll          vector<vll>
#define pll           pair<ll, ll>
#define vpll          vector<pll>
#define vvpll         vector<vpll>
#define endl '\n'
#define all(xs)       xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t;
    cin >> t;

    while(t--) {
        ll n, k;
        cin >> n >> k;

        vll a(n);
        vll b(n);

        for(ll &i: a)
            cin >> i;

        ll x=-1;
        ll ways=1;

        ll mn = 0;
        ll smallest = k;
        for(ll i=0; i<n; i++) {
            cin >> b[i];
            if(b[i]!=-1) {
                if(x==-1)
                    x = a[i]+b[i];
                else if(x!=a[i]+b[i])
                    ways=0;
            }
            smallest = min(smallest, a[i]);
            mn = max(mn, a[i]);
        }

        if(x!=-1)
            for(ll i=0; i<n && ways; i++)
                if(x-a[i] > k || a[i] > x)
                    ways = 0;

        if(ways==0) {
            cout << 0 << '\n';
            continue;
        }
        else if(x!=-1 && ways==1) {
            cout << 1 << '\n';
            continue;
        }

        ll mx = smallest + k;

        cout << mx - mn + 1 << '\n';
    }

    return 0;
}