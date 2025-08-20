// brute force solution

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

        bool ok1 = true;
        bool ok2 = true;
        int counter=0;
        while(ok1) {
            ok1 = false;
            ok2 = false;
            rep(i, 0, n) {
                if(a[i] > b[i] && !ok1) {
                    ok1 = true;
                    a[i]--;
                }
                else if(a[i] < b[i] && !ok2) {
                    ok2 = true;
                    a[i]++;
                }
            }

            if(ok1)
                counter++;
        }

        cout << counter+1 << "\n";
    }

    return 0;
}