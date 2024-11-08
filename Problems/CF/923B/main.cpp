#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll t, n, a;
    string ans;

    cin>>t;
    while(t--)
    {
        ans="";

        cin >> n;
        vector<ll> counters (2*1e6, 0);

        while(n--)
        {
            cin >> a;

            ans += ('a' + counters[a]);
            counters[a]++;  
        }

        cout << ans << endl;
    }

    return 0;
}