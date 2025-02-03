#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;

    map<string, string> mp;
    mp["N"] = "S";
    mp["S"] = "N";
    mp["NE"] = "SW";
    mp["SW"] = "NE";
    mp["NW"] = "SE";
    mp["SE"] = "NW";
    mp["W"] = "E";
    mp["E"] = "W";

    cout << mp[s] << '\n';

    return 0;
}