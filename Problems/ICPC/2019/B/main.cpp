#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;

    int high = -1, save;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if(!i) save = num;

        high = max(num, high);
    }

    if(save == high) cout << "S";
    else cout << "N";
    cout << '\n';
}