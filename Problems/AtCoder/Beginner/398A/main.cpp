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
    ll n;
    cin >> n;

    string ans="";
    if(n & 1) {
        for(ll i=0; i<n/2; i++)
            ans += '-';
        cout << ans << '=' << ans << '\n';
    }
    else {
        for(ll i=0; i<(n/2)-1; i++)
            ans += '-';
        ans += '=';
        cout << ans;
        reverse(all(ans));
        cout << ans << '\n';
    }

    return 0;
}