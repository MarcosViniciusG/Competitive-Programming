#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector <ll>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define endl '\n'
#define all(xs) xs.begin() , xs.end()
#define found (x, xs) (xs.find (x) != xs.end())

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;
    cin >> n;

    string ans="";
    for(ll i=1; i<=n; i++) {
        if(i % 3==0)
            ans += 'x';
        else
            ans += 'o';
    }

    cout << ans << '\n';
    return 0;
}