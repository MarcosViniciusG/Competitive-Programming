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

ll e(ll a, ll b){
    ll na=a;
    while(b--) {
        na *= a;
    }
    return na;
}

signed main() {
    dedinhos;
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        vll x;
        per(i, 16, 0) {
            ll p10 = e(10, i);
            if(n % (1 + p10) == 0)
                x.push_back(n / (1 + p10));
        }

        cout << x.size() << "\n";
        for(auto e: x)
            cout << e << ' ';
        if(x.size()!=0)
            cout << '\n';
    }


    return 0;
}