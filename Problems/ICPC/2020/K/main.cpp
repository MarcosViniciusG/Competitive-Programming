#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define all(xs) xs.begin(), xs.end()
#define eb emplace_back

signed main() {
    ll p, f;
    cin >> p >> f;

    if (p & 1) {
        cout << "N\n";
        return 0;
    }

    vvll g(p + 1);
    while (f--) {
        ll u, v;
        cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }

    vector<bool> vs(p + 1);
    auto dfs = [&](auto& self, ll u) -> ll {  
        vs[u] = true;
        ll res = 1;
        for (ll v : g[u]) if (!vs[v])
            res += self(self, v);
        return res;
    };

    vll qs;

    for (ll i = 1; i <= p; ++i)
        if (!vs[i])
            qs.eb(dfs(dfs, i));

    if (qs.size() > 2)
        cout << "N\n";
    else if (qs.size() == 2) {
        if (qs[0] & 1 and qs[1] & 1)
            cout << "Y\n";
        else
            cout << "N\n";
    }
    else
        cout << "Y\n";
}