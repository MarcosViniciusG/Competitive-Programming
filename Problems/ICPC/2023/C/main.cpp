#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(xs) xs.begin(), xs.end()

signed main() {
    ll n;
    cin >> n;

    vvll g(n + 1);
    for (ll i = 0; i < n - 1; ++i) {
        ll pi;
        cin >> pi;
        g[pi].emplace_back(i + 2);
        g[i + 2].emplace_back(pi);
    }

    vll points(n + 1);
    for (ll i = 1; i <= n; ++i)
        cin >> points[i];

    vll dp(n + 1);
    vll ss;
    auto dfs = [&](auto& self, ll u, ll p) -> void {    
        ll j = lower_bound(all(ss), points[u]) - ss.begin();
        bool removeee = false;
        if (j == ss.size()) {
            ss.emplace_back();
            removeee = true;
        }
        ll ant = ss[j];
        ss[j] = points[u];
        dp[u] = ss.size();
        // for (ll s : ss)
        //     cout << s << ' ';
        // cout << '\n';
        for (ll v : g[u]) if (v != p)
            self(self, v, u);

        if (removeee) ss.pop_back();
        else ss[j] = ant;
    };

    dfs(dfs, 1, 0);
    for (ll i = 2; i <= n; ++i)
        cout << dp[i] << ' ';
    cout << '\n';
}