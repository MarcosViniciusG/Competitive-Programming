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
    
    int n, count = 0;
    cin >> n;

    vll lasts(1e6 + 1);
    rep(i, 0, n)
    {
        int a;
        cin >> a;

            if (lasts[a] == 0) {
                ++count;
            }
            else
                lasts[a]--;
            if (a >= 1)
            lasts[a - 1]++;
    }

    cout << count << '\n';

    return 0;
}