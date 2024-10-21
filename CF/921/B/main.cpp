#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll t, x, n, i, j, gcd;
    cin >> t;
    for(i=0; i<t; i++)
    {
        gcd = 0;
        cin >> x >> n;
        ll biggest = floor(x / (n*1.0));
        while(x % biggest)
        {
            biggest--;
        }

        cout << biggest << endl;
    }

    
    return 0;
}