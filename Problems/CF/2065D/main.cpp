#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m;

    ll t;

    cin >> t;

    while (t--)
    {
        ll ai;
        cin >> n >> m;
        ll prod = n * m;

        vector<pll> v;

        for (ll i = 0; i < n; i++)
        {
            vll a;
            ll soma = 0;
            ll factor = prod;
            ll off = 0;
            for (ll j = 0; j < m; j++)
            {
                cin >> ai;
                a.push_back(ai);
                soma += ai * factor;
                off += ai * m;
                factor--;
            }

            v.push_back({soma, off});
        }

        ll ans = 0;
        ll delta = 0;
        bool used[n] = {false};
        for (ll k = 0; k < n; k++)
        {
            ll best = 0;
            ll best_i = 0;

            for (ll i = 0; i < n; i++)
            {
                ll soma = v[i].first;
                ll off = v[i].second;
                if (!used[i] && (soma-(delta*off) > best))
                {
                    best = soma-delta*off;
                    best_i = i;
                }
            }
            used[best_i] = true;
            ans += best;
            delta++;
        }

        cout << ans << '\n';
    }

    return 0;
}