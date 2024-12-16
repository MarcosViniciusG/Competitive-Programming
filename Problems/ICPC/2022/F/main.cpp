#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n'
#define all(xs) xs.begin(), xs.end()
#define found(x, xs) (xs.find(x) != xs.end())
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define per(i, b, a) for (ll i = (b); i >= (a); --i)
#define x first
#define y second

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;

    map<string, ll> freq;
    vector<string> ws(n);

    ll mx = 0;
    rep(i, 0, n) {
        cin >> ws[i];
        ll pos = ws[i].find('*');
        rep(j, 0, 26) {
            string r = ws[i];
            r[pos] = 'a' + j;
            mx = max(mx, ++freq[r]);
        }
    }

    for (auto& [s, v] : freq) {
        if (v == mx) {
            cout << s << ' ' << mx << '\n';
            return 0;
        }
    }
}