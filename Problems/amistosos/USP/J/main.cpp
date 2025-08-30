#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, a, b) for(ll i = (ll)(a); i < (ll)(b); ++i)
#define per(i, a, b) for(ll i = (ll)(a); i >= (ll)(b); --i)

ll dirx[8] = {1, -1, 0, 0, 1, -1, -1, 1};
ll diry[8] = {0, 0, 1, -1, 1, 1, -1, -1};

signed main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<char>> grid (n, vector<char>(n));
    rep(i, 0, n)
    rep(j, 0, n)
        cin >> grid[i][j];

    set<vector<vector<char>>> st;
    vector<vector<vector<char>>> ans;
    ll num=k+1;
    st.insert(grid);
    ans.push_back(grid);
    bool ok = false;
    for(ll i=0; i<k && !ok; i++) {
        rep(y, 0, n) {
            rep(x, 0, n) {
                if(ans[i][y][x]=='#') continue;
                ll counter=0;
                rep(w, 0, 8) {
                    ll ny=y+diry[w];
                    ll nx=x+dirx[w];
                    if(ny < 0 || ny >= n) continue;
                    if(nx < 0 || nx >= n) continue;
                    if(ans[i][ny][nx]=='1') counter++;
                }
                
                if(ans[i][y][x]=='0' && (counter & 1))
                    grid[y][x] = '1';
                else if(ans[i][y][x]=='1' && (counter & 1))
                    grid[y][x] = '0';
            }
        }

        cout << i << ":\n";
        rep(y, 0, n) {
            rep(x, 0, n)
                cout << grid[y][x];
            cout << '\n';
        }

        if(st.find(grid)!=st.end()) {
            num = i+2;
            ok = true;
        }
        else {
            st.insert(grid);
            ans.push_back(grid);
        }

        // auto it = st.begin();
        // while (it!=st.end())
        // {
        //     rep(y, 0, n) {
        //         rep(x, 0, n)
        //             cout << (*it)[y][x];
        //         cout << '\n';
        //     }
        //     cout << '\n';
        //     it++;
        // }
    }

    rep(i, 0, n) {
        rep(j, 0, n)
            cout << ans[k % num][i][j];
        cout << '\n';
    }
}