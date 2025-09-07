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

// if a is odd and b is odd, k = b
// if a is odd and b is even, try to make a even and keep b even (biggest p2)
// if a is even and b is odd, it's impossible:
// there is no k such that a*k is odd and b is always odd (e + o = o)
// if a is even and b is even, 

signed main() {
    dedinhos;
    ll t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        if((a & 1) && (b & 1)) {
            cout << a*b + 1 << '\n';
        }
        else if((a & 1) && !(b & 1)) {
            ll k = b / 2;
            if((a*k + b/k) % 2 ==0) {
                cout << a*k + b/k << '\n';
            }
            else
                cout << -1 << '\n';
        }
        else if(!(a & 1) && (b & 1))
            cout << -1 << '\n';
        else {
            ll k = b / 2;
            cout << a*k + b/k << '\n';

        }
    }

    return 0;
}