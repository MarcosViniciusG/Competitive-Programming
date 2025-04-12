#include <bits/stdc++.h>
using namespace std;

#define x first 
#define y second 
#define all(xs) xs.begin(), xs.end()

signed main()
{
    int n, t;
    cin >> n >> t;

    vector<pair<int,int>> lista(n);
    for(auto& [a, b] : lista)
    {
        cin >> a >> b;
    }

    vector<pair<int,int>> ord = lista;
    sort(all(ord));

    bool ans = true;
    for(int i = 0; i < n; i++)
    {
        if(ord[i].y != lista[i].y) ans = false;
    }

    cout << (ans ? "Y" : "N") << '\n';
}