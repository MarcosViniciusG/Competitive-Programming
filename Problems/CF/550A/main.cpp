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

    bool BA=false;
    bool AB=false;

    for(int i=0; i<n; i++) {
        if(s.substr(i, 2)=="AB" && !AB) {
            AB = true;
            i++;
        }
        else if(s.substr(i, 2)=="BA" && !BA) {
            BA = true;
            i++;
        }
    }

    bool BA1=false;
    bool AB1=false;

    for(int i=n; i>=2; i--) {
        if(s.substr(i-2, 2)=="AB" && !AB1) {
            AB1 = true;
            i--;
        }
        else if(s.substr(i-2, 2)=="BA" && !BA1) {
            BA1 = true;
            i--;
        }
    }

    cout << (((AB && BA) || (AB1 && BA1)) ? "YES" : "NO") << '\n';
    return 0;
}