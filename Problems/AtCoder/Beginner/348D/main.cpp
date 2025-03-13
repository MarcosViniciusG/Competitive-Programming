#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vll vector <ll>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define endl '\n'
#define all(xs) xs.begin() , xs.end()
#define found(x, xs)(xs.find(x) != xs.end())

ll H, W;
char grid[201][201];
ll starti=-1, startj=-1;
ll goali=-1, goalj=-1;
ll dirx[] = {1, -1, 0, 0};
ll diry[] = {0, 0, 1, -1};

// Returns shortest distance
// between (starti, startj) and
// every other cell
vector<vll> bfs(ll starti, ll startj) {
    vector<vll> dist(H, vll(W, 1000000));
    queue<pll> q;

    q.push({starti, startj});
    dist[starti][startj] = 0;

    while(!q.empty()) {
        pll u = q.front(); q.pop();
        ll i = u.first;
        ll j = u.second;

        for(int k=0; k<4; k++) {
            ll ni=i+diry[k], nj=j+dirx[k];
            if(ni >= H || ni < 0) continue;
            if(nj >= W || nj < 0) continue;
            if(grid[ni][nj]=='#') continue;
            
            // Only change dist if it's a better option
            if(dist[ni][nj] > dist[i][j] + 1) {
                dist[ni][nj] = dist[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    return dist;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> H >> W;
    for(ll i=0; i<H; i++) {
        for(ll j=0; j<W; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') {
                starti = i;
                startj = j;
            }  
            else if(grid[i][j] == 'T') {
                goali = i;
                goalj = j;
            }
        }
    }

    ll N, ri, ci, ei;
    cin >> N;
    vector<pair<ll, pll>> remedies;
    for(ll i=0; i<N; i++) {
        cin >> ri >> ci >> ei;
        ri--; ci--;
        remedies.push_back({ei, {ri, ci}});
    }

    remedies.push_back({0, {starti, startj}});
    remedies.push_back({0, {goali, goalj}});

    N = remedies.size();

    // Check if it's possible to reach the j-th medicine
    // after consuming the i-th medicine (create a new graph)
    bool reachable[N][N];
    memset(reachable, false, sizeof(reachable));
    for(ll i=0; i<N; i++) {
        pll u = remedies[i].second;
        ll r1 = u.first;
        ll c1 = u.second;
        ll e = remedies[i].first;
        vector<vll> dist = bfs(r1, c1);
        for(ll j=0; j<N; j++) {
            pll v = remedies[j].second;
            ll r2 = v.first;
            ll c2 = v.second;
            if(dist[r2][c2] <= e)
                reachable[i][j] = true;
        }
    }

    queue<ll> q;

    // Start with the (fake) medicine with value 0
    // at the starting point
    q.push(N-2);
    bool visited[N];
    memset(visited, false, sizeof(visited));
    visited[N-2] = true;
    while(!q.empty()) {
        ll i = q.front(); q.pop();
        for(ll j=0; j<N; j++) {
            if(!reachable[i][j]) continue;
            if(visited[j]) continue;

            visited[j] = true;
            q.push(j);
        }
    } 

    // Check if the last medice was visited
    cout << (visited[N-1] ? "Yes" : "No") << '\n';

    return 0;
}