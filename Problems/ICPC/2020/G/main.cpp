#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    int init = 100;
    int high = 100;
    while(n--)
    {
        int num;
        cin >> num;

        init+=num;
        high = max(high, init);
    }

    cout << high <<'\n';
    return 0;
}