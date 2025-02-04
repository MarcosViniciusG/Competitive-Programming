#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;

    priority_queue<pair<ll, string>> pq;
    vector<string> v;
    for (int i = 0; i < (2 * n - 2); i++)
    {
        string s;
        cin >> s;

        pq.push({ll(s.length()), s});
        v.push_back(s);
    }

    set<string> pre;
    set<string> suff;

    string u_suff = pq.top().second;
    ll len = pq.top().first;
    pq.pop();

    string u_pre = pq.top().second;
    pq.pop();

    pre.clear();
    suff.clear();
    for (ll i = 0; i < len; i++)
    {
        pre.insert(u_pre.substr(0, i + 1));
        suff.insert(u_suff.substr(i, len - i));
    }

    int sn = 0, pn = 0;

    vector<string> ans;
    set<ll> slens, plens;
    for (int i = 0; i < (2 * n - 2); i++)
    {
        auto it_pre = pre.find(v[i]);
        auto it_suff = suff.find(v[i]);
        if (it_pre != pre.end() && it_suff != suff.end())
        {
            ll l = v[i].length();
            if (slens.find(l) == slens.end())
            {
                slens.insert(l);
                ans.push_back("S");
            }
            else
            {
                plens.insert(l);
                ans.push_back("P");
            }
        }
        else if (it_pre != pre.end())
        {
            pn++;
            ans.push_back("P");
        }
        else if (it_suff != suff.end())
        {
            sn++;
            ans.push_back("S");
        }
    }

    if (ll(ans.size()) != (2 * n - 2))
    {
        string place = u_suff;
        u_suff = u_pre;
        u_pre = place;

        for (ll i = 0; i < len; i++)
        {
            pre.insert(u_pre.substr(0, i + 1));
            suff.insert(u_suff.substr(i, len - i));
        }

        sn = 0; pn = 0;

        ans.clear();
        slens.clear(); plens.clear();
        for (int i = 0; i < (2 * n - 2); i++)
        {
            auto it_pre = pre.find(v[i]);
            auto it_suff = suff.find(v[i]);
            if (it_pre != pre.end() && it_suff != suff.end())
            {
                ll l = v[i].length();
                if (slens.find(l) == slens.end())
                {
                    slens.insert(l);
                    ans.push_back("S");
                }
                else
                {
                    plens.insert(l);
                    ans.push_back("P");
                }
            }
            else if (it_pre != pre.end())
            {
                pn++;
                ans.push_back("P");
            }
            else if (it_suff != suff.end())
            {
                sn++;
                ans.push_back("S");
            }
        }

        for(auto e: ans)
            cout << e;
        cout << '\n';
    }
    else
    {

        for (auto e : ans)
        {
            cout << e;
        }
        cout << '\n';
    }

    return 0;
}