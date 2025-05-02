#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n, c, t, total=0;
    cin >> n >> c >> t;

    vector<int> popcorn(n);
    for(auto& p : popcorn) cin >> p;

    for(auto& p : popcorn)
    {
        int buff = p/t;
        int rest = p%t;
        p = buff;
        if(rest) p+=1;

        total += p;
    }

    int avg, mod;
    avg = total/c, mod = total%c;
    if(mod) avg++;

    vector<int> g;
    int buffer = 0, save = 0;
    for(int i = 0; i < n; i++)
    {
        if(g.size() >= c)
        {
            save += popcorn[i];
        }

        else{
            if(buffer + popcorn[i] > avg)
            {
                g.push_back(buffer);
                buffer = 0;

                if(g.size() == c) save += popcorn[i];
            }
            buffer += popcorn[i];
        }
    }

    if(buffer && !save) g.push_back(buffer);

    int endsum = g.back() + save;

    //g.push_back(save);
    //cout << save << '\n';
    int comp = 1e10+10;

    //for(auto p : g) cout << p << " ";
    //cout << '\n';

    for(int i = 1; i < g.size(); i++)
    {
        int sum = g[i] + g[i-1];
        comp = min(comp, sum);
    }

    if(comp > endsum)
    {
        g.push_back(endsum);
        g.push_back(save);
    }
    else {g.push_back(comp);}

    //for(auto p : g) cout << p << " ";
    //cout << '\n';

    sort(g.begin(), g.end());

    cout << g.back() << '\n';

    return 0;
}