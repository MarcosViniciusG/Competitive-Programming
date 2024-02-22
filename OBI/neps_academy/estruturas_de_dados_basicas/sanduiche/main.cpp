#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll N, D, C, i, j;
    vector<pair<ll, ll>> pares;

    cin >> N >> D;
    vector<ll> prefixes;
    vector<ll> pedacos;
    prefixes.push_back(0);
    for(i=1; i<=N; i++)
    {
        cin >> C;
        prefixes.push_back(prefixes[i-1] + C);
        pedacos.push_back(C);
    }
    
    if(prefixes[N] < D)
    {
        cout << "0\n";
        return 0;   
    }

    for(i=0; i<N; i++) prefixes.push_back(prefixes[N+i] + pedacos[i]);

    j=1;
    for(i=1; i<=N; i++)
    {
        while((prefixes[j+1] - prefixes[i-1])<=D && j<2*N) j++;

        if((prefixes[j] - prefixes[i-1])==D) pares.push_back(make_pair(i, j));
    }

    // for(auto par: pares)
    // {
    //     cout << "(" << par.first << ", " << par.second << ")" << endl;
    // }

    cout << pares.size() << endl;

    return 0;
}