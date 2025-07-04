#include <bits/stdc++.h>
using namespace std;

#define x first 
#define y second

signed main()
{
    int n;
    cin >> n;

    int lasttime = 0;
    vector<int> vtime;
    while(n--)
    {
        string s;
        cin >> s;

        lasttime += (s[0]- '0') * 60;
        lasttime += (s[2] - '0') * 10;
        lasttime += s[3] - '0';

        vtime.push_back(lasttime);
        lasttime = 0;
    }

    int totaldiff = 0;
    pair<int,int> lasttime2 = make_pair(0, 0);
    bool twoguarantee = false, threeguarantee = false;

    for(int i = 0; i < vtime.size(); i++)
    {
        totaldiff = vtime[i] - lasttime2.x;
        //cout << totaldiff << ": " << vtime[i] << " - " << lasttime2.x << '\n'; 
        if(totaldiff <= 10)
        {
            if(i - lasttime2.y == 2) threeguarantee = true;
            else if (i - lasttime2.y == 1) twoguarantee = true;
        }

        if(totaldiff > 10 || !i) 
        {
            if(i - lasttime2.y > 1) i--;
            lasttime2.x = vtime[i];
            lasttime2.y = i;
            totaldiff = 0;
        }
    }
    if(twoguarantee && !threeguarantee) cout << 1;
    else if(threeguarantee) cout << 0;
    else cout << 2;
    cout << '\n';
    return 0;
}