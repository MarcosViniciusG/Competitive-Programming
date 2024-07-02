#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll t, sx, sy, ex, ey;
    cin >> t >> sx >> sy>> ex >> ey;

    string directions;
    cin.ignore(1, '\n');
    getline(cin, directions);

    ll x = sx - ex;
    ll y = sy - ey;

    ll seconds = 1;
    for(auto c: directions)
    {
        if(x > 0 && c=='W')
            x -= 1;
        else if(x < 0 && c=='E')
            x += 1;
        else if(y < 0 && c=='N')
            y += 1;
        else if(y > 0 && c=='S')
            y -= 1;
        
        if(x!=0 || y!=0)
            seconds++;
    }

    if(x==0 && y==0)
        cout << seconds;
    else
        cout << -1;

    cout << endl;

    return 0;
}