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
    ll n_heavy=0;
    ll n_metal=0;
    ll total=0;
    for(ll i=0; i<n; i++) {
        if(s.substr(i, 5)=="heavy") {
            n_heavy++;
        }
        else if(s.substr(i, 5)=="metal") {
            n_metal++;
            total += n_heavy;
        }
    }

    cout << total << '\n';
    return 0;
}