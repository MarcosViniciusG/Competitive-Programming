#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll C, comprimento, i, fabricados=0;
    set<ll> estoque;
    cin >> C;
    for(i=0; i<C; i++)
    {
        cin >> comprimento;
        if(estoque.find(comprimento)!=estoque.end()) estoque.erase(comprimento);
        else
        {
            fabricados += 2;
            estoque.insert(comprimento);
        }
    }

    cout << fabricados << endl;
    return 0;
}