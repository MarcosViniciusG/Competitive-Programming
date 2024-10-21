#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll C, N, P, V, i;
    cin >> C >> N;

    map<ll, ll>mp;
    map<ll, ll> atualizar;
    for(i=0; i<C; i++)
    {
        cin >> P >> V;
        mp[P] = V;
    }

    for(i=0; i<N; i++)
    {
        cin >> P >> V;
        if ((mp.find(P) == mp.end()) || (V > mp[P]))
        {
            atualizar[P] = V;
            mp[P] = V;
        }
    }

    for(auto e: atualizar)
    {
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}