#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, b;
    cin >> n;
    vector<ll> bs;
    while(n--)
    {
        cin >> b;
        bs.push_back(b);
    }

    sort(bs.begin(), bs.end());
    ll biggest = bs[bs.size()-1];
    ll smallest = bs[0];
    ll mx = biggest - smallest;
    ll bigs=0;
    ll smalls=0;
    for(ll i=0; i< bs.size() && mx!=0; i++)
    {
        if(bs[i]==biggest)
            bigs += 1;
        else if(bs[i]==smallest)
            smalls += 1;
    }

    for(ll i=0; i< bs.size() && mx==0; i++)
    {
        bigs += i;
        smalls = 1;
    }

    cout << mx << " " << bigs * smalls << endl;
    return 0;
}