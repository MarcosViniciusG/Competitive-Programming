#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, a, i;
    cin >> n;
    vector<ll> as;
    map<ll, ll> xs;
    ll last[100001];
    ll removed[100001] = {0};

    for(i=0; i<n; i++)
    {
        cin >> a;
        as.push_back(a);

        if(xs.find(a) == xs.end() && removed[a]==0)
            xs[a] = 0;
        else if(removed[a]==0)
        {
            if(xs[a]==0)
                xs[a] = i - last[a];
    
            else if(i - last[a] != xs[a] && removed[a]==0)
            {
                removed[a] = 1;
                xs.erase(a);
            }
        }
        last[a]= i;
    }

    cout << xs.size() << endl;

    for(auto p: xs)
    {
        cout << p.first << " " << p.second;  

        cout << endl;
    }


    return 0;
}