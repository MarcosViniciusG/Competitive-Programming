#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, a, i, j;
    vector<ll> v;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(v[j] > v[j+1])
                swap(v[j], v[j+1]);
        }
    }

    for(auto e: v)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}