#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


#define ll long long
#define pll pair<ll, ll>
using oset = tree<ll, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update>;
#define vpll vector<pll>
#define vll vector<ll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

signed main() {
    ll n;
    cin >> n;
    vpll xs(n);
    for (auto& [a, d] : xs) cin >> a >> d;
    ll a1, a2, d1, d2;
    cin >> a1 >> d1 >> a2 >> d2;

    vpll v1, v2;
    rep(i, 0, 1 << (n / 2)) {
        ll a = 0, d = 0;
        rep(j, 0, n) if (i & (1 << j))
            a += xs[j].first, d += xs[j].second;
        v1.eb(a, d);
    }
    rep(i, 0, 1 << ((n + 1) / 2)) {
        ll a = 0, d = 0;
        rep(j, 0, (n + 1) / 2) if (i & (1 << j))
            a += xs[j + n / 2].first, d += xs[j + n / 2].second;
        v2.eb(a, d);
    }

    sort(all(v1));
    sort(all(v2));
    cout << v1.size() << '\n';
    cout << v2.size() << '\n';
    // return 0;
    // for (auto [x, y] : v2) cout << x << ' ' << y << '\n';
    // return 0;
    ll N = v1.size(), M = v2.size();
    
    ll l = 0, r = 0;

    oset rb;

    ll ans = 0;
    if (a1 <= 0 && 0 <= a2 && d1 <= 0 && d2 <= 0)
        --ans;

    rep(i, 0, N) {
        auto [a, d] = v1[i];
        // if (r < M) cout << d << '\n';
        while (r < M && (a1 <= v2[r].first + a) && (v2[r].first + a <= a2)) {
            rb.insert(v2[r].second);
            ++r;
        }
        while (l < r && a2 < v2[l].first + a) {
            ll p = v2[l].second;
            auto it = rb.upper_bound(p);
            rb.erase(it);
            ++l;
        }

        ll x = d1 - d;
        ll y = d2 + 1 - d;
        ll i1 = rb.order_of_key(x);
        ll i2 = rb.order_of_key(y);
        ans += i2 - i1;

        cout << "----\n";
        for (auto a : rb)
            cout << a << ' ';
        cout << "\n----\n";
    }

    cout << ans << '\n';
}