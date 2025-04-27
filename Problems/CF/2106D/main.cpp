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
        ll n, m;
        cin >> n >> m;

        map<ll, ll> a;
        ll ai;
        for(ll i=0; i<n; i++) {
            cin >> ai;
            a[i]++;
        }

        vll b(m);
        for(ll i=0; i<m; i++) {
            cin >> b[i];
        }
        sort(all(b));

        for(ll i=0; i<m; i++) {
            auto it = a.lower_bound(b[i]);
            if(it!=a.end()) {
                a[(*it).first]--;
                if(a[(*it).first]==0)
                    a.erase(it);
            } 
        }

        if(a.size()==1)
            cout << (*(a.begin())).first;
        else if(a.size()==0)
            cout << 0;
        else
            cout << -1;
        cout << '\n';
    }

    return 0;
}