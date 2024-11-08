#include <bits/stdc++.h>

using ll = long long;
using namespace std;
int main()
{
    ll x=0, y=0;
    ll x1, x2, y1, y2;
    ll x3, x4, y3, y4;
    ll x5, x6, y5, y6;
    cin >> x1 >> x2 >> y1 >> y2;
    cin >> x3 >> x4 >> y3 >> y4;
    cin >> x5 >> x6 >> y5 >> y6;

    ll com = x2 - x1;
    ll h = y2 - y1;
    x += com - (x2 - x4) - (x3 - x1); // >= com
    y += h - (y2 - y4) - (y3 - y1); 
    x += com - (x2 - x6) - (x5 - x1);
    y += h - (y2 - y6) - (y5 - y1); // >= h

    if(x >= com && y >= h)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}