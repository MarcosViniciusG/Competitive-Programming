#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define endl '\n'
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(xs) xs.begin() , xs.end()
#define found(x,xs) (xs.find(x) != xs.end())

char grid[1001][1001];
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};

int H, W;

bool magnetic(ll i, ll j) {
    for(int k=0; k<4; k++) {
        ll ni=i+diry[k], nj=j+dirx[k];
        if(ni >= H || ni < 0) continue;
        if(nj >= W || nj < 0) continue;

        if(grid[ni][nj]=='#')
            return true;
    }

    return false;
}

queue<pll> q;

ll ff(ll i, ll j) {
    if(i >= H || i < 0) return 0;
    if(j >= W || j < 0) return 0;
    if(grid[i][j]!='.') return 0;

    grid[i][j] = '*';
    ll degree=1;
    if(magnetic(i, j)) {
        q.push({i, j});
        return degree;
    }
    for(int k=0; k<4; k++) {
        ll ni=i+diry[k], nj=j+dirx[k];
        degree += ff(ni, nj);
    }
    
    return degree;
}

signed main() {
    fastio;
    cin >> H >> W;
    for(int i=0; i<H; i++)
    for(int j=0; j<W; j++)
        cin >> grid[i][j];

    ll best=1;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            best = max(best, ff(i, j));
            while(!q.empty()) {
                pll u = q.front(); q.pop();
                grid[u.first][u.second] = '.';
            }
        }
    }

    cout << best << '\n';

    return 0;
}