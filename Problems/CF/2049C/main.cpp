#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vi = vector<int>;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    ll t, n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        x--; y--;
        vi color(n);

        int i = 0;
        while(i != n) {
            color[(x+i) % n] = i % 2;
            i++;
        }

        if((n & 1) || (y - x) % 2 == 0)
            color[x] = 2;

        for(auto c: color)
            cout << c << ' ';
        cout << '\n';
    }


    return 0;
}