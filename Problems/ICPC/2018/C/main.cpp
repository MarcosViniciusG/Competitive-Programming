#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T, typename S = null_type>
using oset = tree<T, S, less<>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); --i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

ll contarInversoes(const vll& xs) {
    oset<ll> q;
    ll ans = 0;
    per(i, xs.size() - 1, 0) {
        ans += q.order_of_key(xs[i]);
        q.insert(xs[i]);
    }
    return ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    ll x, y, h, v;
    cin >> x >> y >> h >> v;
    vpll ys(h), xs(v);
    for (auto& [y1, y2] : ys)
        cin >> y1 >> y2;
    for (auto& [x1, x2] : xs)
        cin >> x1 >> x2;
    sort(all(ys));
    sort(all(xs));
    vll YS(h), XS(v);
    rep(i, 0, h)
        YS[i] = ys[i].second;
    rep(i, 0, v)
        XS[i] = xs[i].second;
    ll invsy = contarInversoes(YS);
    ll invsx = contarInversoes(XS);
    cout << h + v + h * v + invsy + invsx + 1 << '\n';
}