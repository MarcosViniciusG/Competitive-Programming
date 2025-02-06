#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string n;
    getline(cin, n);
    
    ll digits = n.size();
    ll best = 0;
    sort(n.begin(), n.end());
    do
    {
        for(ll i=1; i<digits; i++) {
            best = max(best, stoll(n.substr(0, i)) * stoll(n.substr(i, digits-i)));
        }
    } while(next_permutation(n.begin(), n.end()));
    
    cout << best << '\n';
    return 0;
}