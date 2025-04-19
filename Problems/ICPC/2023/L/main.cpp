#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(xs) xs.begin(), xs.end()

signed main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n = s.size();
    vector<string> blocks(k);
    for (ll i = 0; i < n; ++i)
        blocks[i % k] += s[i];
    for (string& b : blocks) {
        // cout << b << '\n';
        sort(all(b));
    }
    for (ll i = 0; i < n; ++i)
        cout << blocks[i % k][i / k];
    cout << '\n';
}