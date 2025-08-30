#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define eb emplace_back()

signed main() {
    ll n, d;
    cin >> n >> d;
    vll xs(n);
    for (ll& x : xs) cin >> x;

    ll n1=0;
    ll n2=0;
    ll d1=0;
    ll d2=0;
    rep(i, 0, n) {
        if(d1==0) {
            n1 = i+1;
            d1 = xs[i];
        }
        else if(d2==0) {
            n2 = i+1;
            d2 = xs[i];
        }
    }

    if(d1 < d && d2==0) {
        cout << -1 << '\n';
        return 0;
    }
    else if(d2 < d && d1==0) {
        cout << - 1 << '\n';
        return 0;
    }

    if(d1 >= d) {
        rep(i, 0, d) {
            cout << n1 << ' ';
        }
        cout << '\n';
        return 0;
    }
    else if(d2 >= d) {
        rep(i, 0, d) {
            cout << n2 << ' ';
        }
        cout << '\n';
        return 0;
    }

    rep(i, 0, d) {
        cout << (i&1 ? n1 : n2) << ' ';
    }
    cout << '\n';
}