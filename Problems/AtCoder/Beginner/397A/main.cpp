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
    double x;
    cin >> x;

    if(x >= 38.0)
        cout << "1\n";
    else if(x >= 37.5)
        cout << "2\n";
    else
        cout << "3\n";

    return 0;
}