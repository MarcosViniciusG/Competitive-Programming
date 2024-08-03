#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, x, curr, dist=0;
    vector<ll> v;

    cin >> n;
    while(n--)
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(ll i=0; i<v.size(); i++)
    {
        if(i==0 || curr != v[i])
        {
            dist++;
            curr = v[i];
        }
    }

    cout << dist << endl;
    return 0;
}