#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, m, prev=-1, a, t=0;
    cin >> n >> m;
    while(m--)
    {
        cin >> a;
        if(prev==-1)
        {   
            t += a - 1;
            prev = a;
        }
        else
        {
            if(prev < a)
            {
                t += (a - prev);
            }
            else if(prev > a)
            {
                t += (n - prev) + a;
            }

            prev = a;
        }
    }

    cout << t << endl;
    return 0;   
}