#include <bits/stdc++.h>

using namespace std;

#define ll int
#define vll vector<ll>
#define vvll vector<vll>
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define eb emplace_back
#define all(xs) xs.begin(), xs.end()

#define x first 
#define y second

#define int long long

void backtrack(const vector<pair<pair<int,int>,pair<int,int>>>& xs, vector<pair<int,int>>& ys, int index, set<int> palco, bool flag = true, int mus = 0, int ini = -1, int fim = -1)
{
    if(index >= xs.size())
    {
        ys.push_back(make_pair(palco.size(), mus));
        return;
    }

    if(flag)
    {
        int buffer = index-1;
        int compini = xs[index].x.x;
        while(buffer >= 0)
        {
            if(xs[buffer].x.y <= compini)
            {
                palco.insert(xs[buffer].y.y);
                mus += xs[buffer].y.x;
                compini = xs[buffer].x.x;
            }
            buffer--;
        }
    }

    if(xs[index].x.x >= fim)
    {
        palco.insert(xs[index].y.y);
        mus += xs[index].y.x;
        backtrack(xs, ys, index+1, palco, false, mus, xs[index].x.x, xs[index].x.y);
    }

    else backtrack(xs, ys, index+1, palco, false, mus, ini, fim);
}

signed main()
{
    int n;
    cin >> n;

    /* for(int i=0; i<11; i++) {
        for(int j=0; j<MAXN; j++) {
            dp[i][j] = -1;
        }
    } */

    vector<pair<pair<int,int>,pair<int,int>>> xs;
    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        for(int j = 0; j < m; j++)
        {
            int ini, fim, op;
            cin >> ini >> fim >> op;

            xs.push_back(make_pair(make_pair(ini, fim), make_pair(op, i)));
        }
    }

    vector<pair<int,int>> ys;
    sort(all(xs));
    set<int> buff;

    for(int i = 0; i < xs.size(); i++) backtrack(xs, ys, i, buff);
    sort(all(ys));
    if(ys.back().x != n) cout << -1 << '\n';
    else cout << ys.back().y << '\n';

    /* for(auto [a, b] : ys)
    {
        cout << a << " " << b << '\n';
    } */

    return 0;
}