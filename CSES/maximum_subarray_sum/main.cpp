#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll n, x, i, maior, menor;
    cin >> n;
    vector<ll> prefixes;
    prefixes.push_back(0);

    for(i=1; i<=n; i++)
    {
        cin >> x;
        prefixes.push_back(prefixes[i-1] + x);
    }

    maior = prefixes[1];
    menor = 0;
    for(i=1; i<=n; i++)
    {
        maior = max(maior, prefixes[i] - menor);
        menor = min(menor, prefixes[i]);
    }
    cout << maior << endl;
    return 0;
}