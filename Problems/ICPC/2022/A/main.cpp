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
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll v = 0, ans = 0;

    rep(i, 0, n) {
        if (s[i] == 'a')
            ++v;
        else {
            if (v != 1)
            ans += v;
            v = 0;
        }
    }

    if (v != 1)
    ans += v;

    cout << ans << '\n';
    return 0;
}