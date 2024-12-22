#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    char grid[h][w];
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> grid[i][j];
        }
    }

    string s;
    cin >> s;

    map<char, pll> mp;
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};
    mp['L'] = {0, -1};
    mp['R'] = {0, 1};

    ll counter=0;
    for(auto c: s) {
        pll moves= mp[c];
        ll xi=x + moves.first;
        ll yi=y+ moves.second;

        if((xi < h) && (yi<w) && (grid[xi][yi]!='#')) {
            x = xi;
            y = yi;
            if(grid[xi][yi]=='@') {
                counter++;
                grid[xi][yi] = '.';
            }
        }
    }
    cout << x+1 << " " << y+1 << " " << counter << '\n';

    return 0;
}