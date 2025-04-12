#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()

struct WaveletTree {
    WaveletTree(vll& xs, ll n) : wav(2 * n), nn(xs.size()) {
        auto build = [&](auto&self, auto b, auto e, ll l, ll r, ll no) {
            if (l == r) return;
            ll m = (l + r) / 2, i = 0;
            wav[no].resize(e - b + 1);
            for (auto it = b; it != e; ++it, ++i)
                wav[no][i + 1] = wav[no][i] + (*it <= m);
            auto p = stable_partition(b, e, [m](ll x) { return x <= m; });
            self(self, b, p, l,m, 2 * no);
            self(self, p, e, m + 1, r, 2 * no + 1);
        };
        build(build, all(xs), 0, n - 1, 1);
    }

    ll leq(ll i, ll j, ll x) {
        ++j;
        ll l = 0, r = nn - 1, lx = 0, no = 1;
        while (l != r) {
            ll m = (l + r)/ 2;
            ll leqm_l = wav[no][i], leqm_r = wav[no][j];
            no *= 2;
            if (x <= m) i = leqm_l, j = leqm_r, r = m;
            else i -= leqm_l, j -= leqm_r, l = m + 1, lx = leqm_r - leqm_l, ++no;
        }
        return j - i + lx;
    }

    vvll wav;
    ll nn;
};

template <typename T>
pair<map<T, ll>, map<ll, T>> compress(vector<T>& xs) {
    ll i = 0;
    set<T> ys(all(xs));
    map<ll, T> pm;
    map<T, ll> mp;
    for (T y : ys) {
        pm[i] = y;
        mp[y] = i++;
    }
    return {mp, pm};
}

signed main() {
    ll y, n;
    cin >> y >> n;

    vll xs(y);
    for (ll i = 0; i < y; ++i)
        cin >> xs[i];
    auto [mp, pm] = compress(xs);
    for (ll& x: xs) {
        x = mp[x];
        cout << x << ' ';
    }
    cout << '\n';
    vll ys = xs;
    WaveletTree wv(xs, mp.size());
    cout << wv.leq(0, 4, 0) << '\n';
    cout << wv.leq(0, 4, 1) << '\n';
    cout << wv.leq(0, 4, 2) << '\n';
    cout << wv.leq(2, 4, 3) << '\n';
    cout << wv.leq(0, 4, 4) << '\n';
    return 0;
    for (ll i = 0; i < n; ++i) {
        ll year, pos, len;
        cin >> year >> pos >> len;
        --year;
        // cout << ys[year] << ' ' << pos << ' ' << year + 1 << ' ' << y << '\n';
        // cout << wv.leq(year + 1, min(y - 1, year + len), pos) << '\n';
        // cout << pos << '\n';
        cout << len << ' ' << wv.leq(year + 1, min(y - 1, year + len), pos - 1) << '\n';
        if (ys[year] < pos and year + 1 < y) {
            cout << len - wv.leq(year + 1, min(y - 1, year + len), pos - 1) << '\n';
            // cout << year + 1 << ' ' << year + len << '\n';
        }
        else
            cout << 0 << "\n";
    }
}