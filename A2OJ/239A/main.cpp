#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    ll y, k, n;
    cin >> y >> k >> n;

    bool printed = false;
    ll first = (((y / k) + 1) * k) - y;
    
    for(ll x=first; (x+y) <= n; x+= k) {
        printed = true;
        cout << x << " ";
    }

    if(!printed) 
        cout << -1;

    cout << endl;

    return 0;
}