#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
#define endl '\n'

int H, W, K;
char S[10][10];
bool visited[10][10];

ll solve(int i, int j, int k) {
    if(S[i][j]=='#') return 0;
    if(visited[i][j]==true) return 0;
    if(i < 0 || i==H) return 0;
    if(j < 0 || j==W) return 0;
    if(k==K) return 1;

    visited[i][j] = true;

    ll up = solve(i-1, j, k+1);
    ll down = solve(i+1, j, k+1);
    ll left = solve(i, j-1, k+1);
    ll right = solve(i, j+1, k+1);

    visited[i][j] = false;

    // cout << "COORDERNADAS: " << i << " " << j << '\n';
    // cout << "MOVIMENTOS: " << k << '\n';
    // cout << "CIMA: " << up << '\n';
    // cout << "BAIXO: " << down << '\n';
    // cout << "ESQUERDA: " << left << '\n';
    // cout << "DIREITA: " << right << '\n';
 
    return up + down + left + right;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> H >> W >> K;

    vpll emp;
    for(int i=0; i<H; i++)
    for(int j=0; j<W; j++) {
        cin >> S[i][j];
        if(S[i][j]=='.')
            emp.push_back(make_pair(i, j));
    }

    ll total = 0;
    for(ll i=0; i<emp.size(); i++) {
        memset(visited, false, sizeof(visited));
        total += solve(emp[i].first, emp[i].second, 0);
    }
    
    cout << total << '\n';

    return 0;
}