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
        color[x+0] = 0;

        for(ll i=1; i<n; i++) {
            color[(i+x) % n] = abs(1 - color[(x+i-1)%n]);
        }

        if(n & 1 || !((x-y) & 1))
            color[x] = 2;

        for(auto c: color)
            cout << c << ' ';
        cout << '\n';
    }


    return 0;
}