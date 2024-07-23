#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    ll n, li, ri, min, max;
    cin >> n;
    vector<pair<ll,ll>> v; 
    for(ll i=0; i<n; i++)
    {
        cin >> li;
        cin >> ri;

        v.push_back(make_pair(li, ri));

        if(i==0 || li < min)
            min = li;
        if(i==0 || ri > max)
            max = ri;
    }

    for(int i=0; i<n; i++)
    {
        if(v[i] == make_pair(min, max)) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    

    cout << -1 << endl;

    return 0;
}