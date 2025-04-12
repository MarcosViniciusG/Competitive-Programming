#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int b, l;
    cin >> b >> l;

    vector<int> alg(l);
    string snum = "";

    for(auto& x : alg)
    {
        cin >> x;
        snum += (x+'0');
    }

    if(!(stoi(snum)%(b+1)))
    {
        cout << 0 << " " << 0 << '\n';
        return 0;
    }

    for(int i = 0; i < l; i++)
    {
        for(int j = alg[i]-1; j >= 0; j--)
        {
            string s = snum;
            s[i] = (j + '0');
            if(!(stoi(s)%(b+1)))
            {
                cout << i+1 << " " << j << '\n';
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << '\n';
}