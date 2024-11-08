#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() 
{
    ll t, x, y, num, base, diff;
    cin >> t;
    while(t--)
    {
        cin >> y >> x;
        if(x==1 && y==1)
            num = 1;
        else if(y>=x)
        {
            base = (y*y) - (y-1);
            diff = y-x;

            if(y%2==0)
                num = base + diff;
            else
                num = base-diff;
        }
        else if(x>y)
        {
            base = (x*x) - (x-1);
            diff = x-y;
            if(x%2==0)
            {
                num = base - diff;
            }
            else
            {
                num = base + diff;
            }
        }
        // cout << base << " " << diff << endl;

        cout << num << endl;
    }
    return 0;
}