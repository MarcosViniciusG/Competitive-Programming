#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int H, W, D;
char S[1001][1001];

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};
bool visited[1001][1001];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> H >> W >> D;
    queue<pair<ll, pll>> q;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> S[i][j];
            if(S[i][j]=='H') {
                q.push({0, {i, j}});
            }
        }
    }

    memset(visited, false, sizeof(visited));

    // BFS
    while (!q.empty())
    {
        pair<ll, pll> u = q.front(); q.pop();
        ll dis = u.first;
        ll i = u.second.first;
        ll j = u.second.second;

        visited[i][j] = true;
        for(int k=0; k<4; k++) {
            ll ni = i+diry[k], nj = j+dirx[k];
            if(ni >= H || ni < 0) continue;
            if(nj >= W || nj < 0) continue;
            if(S[ni][nj]!='.') continue;
            if(dis + 1 > D) continue;
            if(visited[ni][nj]) continue;

            q.push({dis+1, {ni, nj}});
        }
    }

    ll ans=0;
    for(ll i=0; i<H; i++)
    for(ll j=0; j<W; j++)
        if(S[i][j] != '#' && visited[i][j])
            ans++;

    cout << ans <<'\n';

    return 0;
}