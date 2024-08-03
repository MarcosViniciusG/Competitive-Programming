#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, x, a, pos1, pos2;
    bool found = false;
    cin >> n >> x;

    map<ll, vector<ll>> mp;

    for(ll i=0; i<n; i++)
    {
        cin >> a;
        mp[a].push_back(i);
    }

    for(auto par: mp)
    {
        pos1 = par.second[0];
        ll diff = x - par.first;
        if(mp.find(diff) != mp.end())
        {
            for(auto i: mp[diff])
            {
                pos2 = i;
                // cout << diff << " " << i << endl;
                if(pos1 != pos2)
                {
                    found = true;
                    break;
                }
            }

            if(found) break;
        } 
    }

    if(found)
        if(pos1 < pos2)
            cout << pos1+1 << " " << pos2+1 << endl;
        else
            cout << pos2+1 << " " << pos1+1 << endl;
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}