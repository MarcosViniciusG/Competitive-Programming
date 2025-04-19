#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;

#define rep(i, start, end) for(ll i=(start); i<ll(end); i++) 

ll ans=0;

vvll floydWarshall(const vvpll &g) {
    ll n = g.size();
    vvll ds(n, vll(n, INT_MAX));

    rep(u, 0, n) {
        ds[u][u] = 0;
        for(auto [w, v]: g[u])
            ds[u][v] = w;
    }
    
    set<pll> st;
    rep(k, 0, n) rep(u, 0, n) {
        rep(v, 0, n)
        if(u!=v && u!=k && k!=v) {
            ll comp = ds[u][k] + ds[k][v];
            if(ds[u][v] > comp) {
                ans = -1;
                return ds;
            }
            else if(ds[u][v] == comp) {
                if(u > v)
                    st.insert({u, v});
                else
                    st.insert({v, u});
            }
        }
    }

    ans = st.size();

    return ds;
}

signed main() {
    ll n;
    cin >> n;

    ll w;
    vvpll g(n);
    rep(i, 0, n) rep(j, 0, n) {
        cin >> w;
        g[i].push_back({w, j});
    }

    vvll res = floydWarshall(g);

    cout << ans << '\n';
    return 0;
}