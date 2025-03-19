#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

signed main() {
    fastio;
    ll t=0;
    ll ti;
    for(ll i=0; i<9; i++) {
        cin >> ti;
        t += ti;
    }

    ll a=0;
    ll ai;
    for(ll i=0; i<8; i++) {
        cin >> ai;
        a+= ai;
    }

    cout << (t-a + 1) << '\n'; 

    return 0;
}