#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll n, q, x_i;

    cin >> n >> q;
    vector<ll> psum (n+1);
    psum[0] = 0; 
    for(ll i=1; i<=n; i++)
    {
        cin >> x_i;
        psum[i] = psum[i-1] + x_i;       
    }

    ll l, r;
    while(q--)
    {
        cin >> l >> r;
        cout << psum[r] - psum[l-1] << endl;
    }

    return 0;
}