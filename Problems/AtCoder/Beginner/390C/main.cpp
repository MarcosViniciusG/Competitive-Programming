#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define endl '\n';

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll h, w;
    cin >> h >> w;
    vector<string> grid;
    string s;
    cin.ignore(1, '\n');
    for(ll i=0; i<h; i++) {
        getline(cin, s);
        grid.push_back(s); 
    }


    bool can = true;
    ll a=2000, b=2000, c=-1, d=-1;
    bool found=false;
    for(ll i=0; i<h; i++) {
        for(ll j=0; j<w; j++) {
            if(grid[i][j]=='#') {
                a = min(a, i);
                c = max(c, i);

                b = min(b, j);
                d = max(d, j);
            }
        }
    }

    for(ll i=a; i<=c; i++) {
        for(ll j=b; j<=d; j++) {
            if(grid[i][j]=='.')
                can = false;
        }
    }
   
    if(a==2000 && b==2000)
        can = false;
    
    cout << (can ? "Yes" : "No") << '\n';

    return 0;
}