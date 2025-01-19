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

    cout << (s[0] - '0') * (s[2] - '0') << '\n';

    return 0;
}