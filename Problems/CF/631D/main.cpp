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
    cin >> n >> m;
    string li, ci;

    vector<pair<ll, char>> t;
    vector<pair<ll, char>> s;
    cin.ignore(1, '\n');
    char prev='#';
    for (ll i = 0; i < n; i++)
    {
        getline(cin, li, '-');
        if (i == n - 1)
            getline(cin, ci);
        else
            getline(cin, ci, ' ');
        
        if(ci[0]!=prev)
            t.push_back({stoll(li), ci[0]});
        else
            t[ll(t.size())-1].first += stoll(li);
        
        prev = ci[0];
    }

    prev='#';
    for (ll i = 0; i < m; i++)
    {
        getline(cin, li, '-');
        if (i == m - 1)
            getline(cin, ci);
        else
            getline(cin, ci, ' ');
        if(ci[0]!=prev)
            s.push_back({stoll(li), ci[0]});
        else
            s[ll(s.size())-1].first += stoll(li);
        
        prev = ci[0];
    }

    n = t.size();
    m = s.size();

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (t[i].second == s[0].second && t[i].first >= s[0].first)
        {
            if (m != 1)
            {
                ll j;
                for (j = 1; j + i < n && j < m; j++)
                {
                    if (j != m - 1 && t[j + i] != s[j])
                        break;
                    else if (j == m - 1 && (t[j + i].second != s[j].second || t[j + i].first < s[j].first))
                        break;
                }
                if (j == m)
                    ans++;
            }
            else
            {
                ans += (t[i].first - s[0].first) + 1;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}