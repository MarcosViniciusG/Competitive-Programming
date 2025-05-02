#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, c, t;
    cin >> n >> c >> t;

    vector<int> popcorn(n);
    for(auto& p : popcorn) cin >> p;

    for(auto& p : popcorn)
    {
        int p /= t;
        int rest = p%t;
        if(rest) p+=1;
    }

    int exp, mod;
    exp = n/c, mod = n%c;

    vector<pair<int, set<int>>> sep;
    int count = 0, buffer = 0;
    set<int> vecbuff;
    for(int i = 0; i < n; i++)
    {
        if(i == n-1)
        {
            sep.push_back(make_pair(buffer, vecbuff));
        }
        else count++;

        buffer += popcorn[i];
        vecbuff.insert(popcorn[i]);

        if(count == exp)
        {
            count=0;
            sep.push_back(make_pair(buffer, vecbuff));
            vecbuff.clear();
            buffer=0;
        }
    }

    for(int i = 0; i < sep.size(); i++)
    {
        for(auto it = sep[i].second.rbegin(); it != sep[i].second.rend(); it++)
        {
            int newbuff = sep[i].first - e;
            for(int j = 0; j < sep.size(); j++)
            {
                if(sep[j].first + e <= newbuff)
                {
                    sep[i].first = newbuff;
                    sep[i].second.erase(e);

                }
            }
        }
    }

    return 0;
}