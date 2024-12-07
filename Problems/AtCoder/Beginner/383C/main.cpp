#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int H, W, D;
char S[1001][1001];
bool visited[1001][1001] = {0};

int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};
 
bool isValid(int i, int j) {
    if(i < 0 || i >= H) return false;
    if(j < 0 || j >= W) return false;
    if(visited[i][j]) return false;
    if(S[i][j]=='#') return false;

    return true;
}

void bfs(ll starty, ll startx) {
    queue<pll> q;
    q.push({starty, startx});
    visited[starty][startx] = true;

    ll d=D;
    while(!q.empty() && d>0) {
        pll par = q.front(); q.pop();
        ll i = par.first;
        ll j = par.second;

        for(ll w=0; w<4; w++) {
            ll adjy = i + dir_y[w];
            ll adjx = j + dir_x[w];

            if(isValid(adjy, adjx)) {
                q.push({adjy, adjx});
                visited[adjy][adjx] = true;
            }
        }
        d--;
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> H >> W >> D;
    queue<pll> q;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> S[i][j];
            if(S[i][j]=='H') {
                q.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        pll par = q.front(); q.pop();
        ll i =par.first;
        ll j = par.second;
        bfs(i, j);
    }
    
    int soma=0;
    for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
        if(visited[i][j]) {
            cout << '-';
            soma++;
        }
        else
            cout << S[i][j];
        }
    cout << '\n'; 
    }

    cout << soma <<'\n';

    return 0;
}