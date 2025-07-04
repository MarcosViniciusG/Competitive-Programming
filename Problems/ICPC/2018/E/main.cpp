#include <bits/stdc++.h>
using namespace std;

using vll = vector<long long>;
#define int long long

vll z(const string& s)
{
    int n = s.size(), l = 0, r = 0;
    vll zs(n);
    for(int i = 1; i < n; i++)
    {
        if(i <= r)
        {
            zs[i] = min(zs[i - l], r - i + 1);
        }
        while(zs[i] + i < n && s[zs[i]] != s[i+zs[i]])
            ++zs[i];
        if(r < i + zs[i] - 1)
            l = i, r = i + zs[i] - 1;
    }
    return zs;
}

signed main()
{
    string s, t;
    cin >> s >> t;

    int tsize = t.size();
    int ssize = s.size();

    string z= t + '#' + s;
    /* vll ans = z(zs);

    int outp = 0;
    for(auto p : ans)
    {
        if(p == tsize)
        {
            outp++;
        }
    } */
    int n = z.size();
    int l = 0, m = tsize+1;
    int r = m;
    int count = 0, ans = 0; 

    while(r < n)
    {
        if(z[l] != z[r])
        {
            count++;
            l++;
            r++;
        }

        else
        {
            count = 0;
            l = 0;
            m++;
            r = m;
        }

        if(count == t.size())
        {
            ans++;
            l = 0;
            count = 0;
            m++;
            r = m;
        }
    } 

    cout << ans << '\n';
}