#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(ll i= a; i< b; ++i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

ll dirx[] = {1, -1, 0, 0};
ll diry[] = {0, 0, 1, -1};
bool visited[1010][1010];
vector<string> graph(1010);
ll n, m;

pair<pll, ll> bfs(pair<pll, ll> initial, bool hasBadge, bool badge) {
    memset(visited, 0, sizeof(visited));
    queue<pair<pll, ll>> q;
    q.push(initial);
    ll ans=-1;
    ll xans=-1, yans=-1;

    while(!q.empty()) {
        pair<pll, ll> u = q.front(); q.pop();
        ll y = u.first.first; 
        ll x = u.first.second;

        if(y < 0 || y >= n) continue;
        if(x < 0 || x >= m) continue;
        if(graph[y][x]=='#') continue;
        if(graph[y][x]=='X' && !hasBadge) continue;

        if(!badge && y==n-1 && x==m-1) {
            xans = x;
            yans = y;
            ans = u.second;
            break;
        }

        if(badge && graph[y][x]=='B') {
            xans = x;
            yans = y;
            ans = u.second;
            break;
        }

        for(ll k=0; k<4; k++) {
            ll ny = y + diry[k]; 
            ll nx = x + dirx[k];
            if(ny < 0 || ny >= n) continue;
            if(nx < 0 || nx >= m) continue;
            if(graph[ny][nx]=='#') continue;
            if(graph[ny][nx]=='X' && !hasBadge) continue;
            if(visited[ny][nx]) continue;

            q.push({{ny, nx}, u.second+1});
            visited[ny][nx] = true;
        }
    }

    return {{yans, xans}, ans};
}

signed main() 
{
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n >> m;

    for(ll i=0; i<n; i++) 
        cin >> graph[i];

    pair<pll, ll> ans1 = bfs({{0, 0}, 0}, false, false);
    pair<pll, ll> ans2 = bfs({{0, 0}, 0}, false, true);

    pair<pll, ll> ans3={{-1, -1}, -1};
    if(ans2.second!=-1) {
        ans3 = bfs(ans2, true, false);
    }

    if(ans1.second==-1 && ans3.second==-1)
        cout << -1 << '\n';
    else if(ans1.second==-1)
        cout << ans3.second << '\n';
    else if(ans3.second==-1)
        cout << ans1.second << '\n';
    else
        cout << min(ans1.second, ans3.second) << '\n';

    return 0;
}