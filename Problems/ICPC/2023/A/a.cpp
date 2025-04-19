#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, alt, c = 0;
    cin >> n >> alt;

    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        if(alt >= k) c++;
    }

    cout << c << '\n';
}