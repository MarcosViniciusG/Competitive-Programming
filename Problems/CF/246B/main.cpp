#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    ll n, ai;
    cin >> n;
    ll sum = 0;
    for(ll i=0; i<n; i++) {
        cin >> ai;
        sum += ai;
    }

    if(sum % n == 0)
        cout << n << endl;
    else
        cout << n-1 << endl;

    return 0;
}