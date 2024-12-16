#include <bits/stdc++.h>

#ifdef LOCAL
#include "../dbg.h"
#else
#define dbg(...)
#endif

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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
using RBT = tree<T, null_type, greater<>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n;
    cin >> n;

    vll as(n), bs(n);
    rep(i, 0, n)
        cin >> as[i];
    rep(i, 0, n)
        cin >> bs[i];

    ll k, l;
    cin >> k >> l;

    ll psum = 0, ssum = 0;
    RBT<pll> xs;

    rep(i, 0, k) {
        psum += as[i];
        xs.insert({ bs[i], i + 1 });
    }

    ll r = n - 1;

    ll soma_l = 0;
    rep(i, 0,l)
        soma_l += xs.find_by_order(i)->first;

    ll ans = psum + soma_l;
    dbg(ans, psum, ssum, soma_l);
    dbg(xs);

    per(i, k - 1, 0) {
        psum -= as[i];
        ssum += as[r];

        if (xs.order_of_key({ bs[i], i + 1 }) < l) {
            soma_l -= bs[i];
            soma_l += xs.find_by_order(l)->first;
        }

        xs.erase({ bs[i], i + 1 });
        xs.insert({ bs[r], r + 1 });

        if (xs.order_of_key({ bs[r], r + 1 }) < l) {
            soma_l += bs[r];
            soma_l -= xs.find_by_order(l)->first;
        }

        --r;
        ans = max(ans, psum + ssum + soma_l);
        dbg(ans, psum, ssum, soma_l);
    }

    cout << ans << '\n';
    return 0;
}