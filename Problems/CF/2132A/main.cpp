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
        string a;
        cin >> a;
        ll m;
        cin >> m;
        string b, c;
        cin >> b;
        cin >> c;

        string pre="";
        string suf="";
        rep(i, 0, m) {
            if(c[i]=='D')
                suf += b[i];
            else
                pre += b[i];
        }   

        reverse(all(pre));

        cout << pre << a << suf << '\n';
    }

    return 0;
}