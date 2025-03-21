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
    ll n, x, y, z;
    cin >> n >> x >> y >> z;

    bool can=false;
    if(y > x && z > x && z < y)
        can = true;
    if(x > y && z > y && z < x)
        can = true; 

    cout << (can ? "Yes" : "No") << '\n';

    return 0;
}