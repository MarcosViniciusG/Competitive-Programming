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

        vector<pair<ll, vll>> v;

        for (ll i = 0; i < n; i++)
        {
            vll a;
            ll soma = 0;
            for (ll j = 0; j < m; j++)
            {
                cin >> ai;
                a.push_back(ai);
                soma += ai;
            }

            v.push_back({soma, a});
        }

        sort(v.begin(), v.end(), greater<pair<ll, vll>>());

        ll ans=0;
        ll off=n*m;
        for(auto par: v) {
            for(auto el: par.second) {
                ans += el * off;
                off--;
            }
        }


        cout << ans << '\n';
    }

    return 0;
}