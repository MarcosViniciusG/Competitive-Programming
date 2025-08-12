#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

vll lis(const vll& xs, bool values) {
    assert(!xs.empty());
    vll ss, idx, pre(xs.size()), ys;
    for(ll i=0; i<xs.size(); i++) {
        // change to upper_bound if want not decreasing
        ll j = lower_bound(all(ss), xs[i]) - ss.begin();
        if (j == ss.size()) ss.eb(), idx.eb();
        if (j == 0) pre[i] = -1;
        else        pre[i] = idx[j - 1];
        ss[j] = xs[i], idx[j] = i;
    }
    ll i = idx.back();
    while (i != -1)
        ys.eb((values ? xs[i] : i)), i = pre[i];
    reverse(all(ys));
    return ys;
}

signed main() {
    ll n;
    cin >> n;

    vll xs(n);
    for(ll i=0; i<n; i++) {
        cin >> xs[i];
    }

    auto ans = lis(xs, false);
    cout << ans.size() << '\n';
    for(auto e: ans)
        cout << e+1 << ' ';
    cout << '\n';

    return 0;
}