#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll x, n, i;
        cin >> x >> n;

        ll ans=1;
        for(i=1; i*i<=x; i++)
        {
            if(x % i==0)
            {
                if(n <= x/i)
                    ans = max(ans, i);
                if(n <= i)
                    ans = max(ans, x/i);

            }
        }

        cout << ans << '\n';
    }
}