#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    ll n = s.length();

    ll last_bear=0;

    ll counter=0;
    for(ll i=0; i<n; i++) {
        if(s.substr(i, 4)=="bear") {
            counter += (i - last_bear + 1) * (n - (i + 3));
            last_bear = i+1;
            i += 3;
        }
    }

    cout << counter << '\n';
    return 0;
}