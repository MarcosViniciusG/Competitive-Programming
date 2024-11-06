#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n, k, q;
    cin >> n >> k >> q;
    ll countries[n][k];
    for(int i=0; i<n; i++)
    for(int j=0; j<k; j++)
        cin >> countries[i][j];
    
    for(int j=0; j<k; j++)
    for(int i=1; i<n; i++) {
        ll result = (countries[i][j] | countries[i-1][j]);
        countries[i][j] = result;
    }

    ll r, c, m;
    char o; 

    for(int z=0; z<q; z++) {
        cin >> m;
        vector<bool> mask(n, true);

        for(int w=0; w<m; w++) {
            cin >> r >> o >> c;

            for(int i=0; i<n; i++) {
                if(o=='>') {
                    if(countries[i][r-1] <= c)
                        mask[i]=false;
                }
                else if(o=='<') {
                    if(countries[i][r-1] >= c)
                        mask[i]=false;
                }
            }
        }
        
        bool found=false;
        for(int y=0; y<n; y++) {
            if(mask[y]) {
                found = true;
                cout << (y+1) << '\n';
                break;
            }
        }

        if(!found)
            cout << -1 << '\n';
    }

    return 0;
}