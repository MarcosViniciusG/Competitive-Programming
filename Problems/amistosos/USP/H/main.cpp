#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)


signed main() {
    ll n;
    cin >> n;

    ll a, b;
    cin >> a >> b;
    vll dislike(a+1, 0);
    ll bi;
    rep(i, 0, b) {
        cin >> bi;
        dislike[bi] = true;
    }

    ll ans=-1;
    ll m;
    ll mi;
    rep(i, 0, n) {
        cin >> m;
        ll counter=0;
        rep(j, 0, m) {
            cin >> mi;
            if(dislike[mi])
                counter++;

            if(counter > m/3 && ans==-1) 
                ans = i+1;
        }
    }

    cout << ans << '\n';
 
}