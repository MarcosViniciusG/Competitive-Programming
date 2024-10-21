#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, x, y, z, tx=0, ty=0, tz=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y >> z;
        tx += x;
        ty += y;
        tz += z;
    }

    if(tx || ty || tz)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}