#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll n, q, a, l, r, i;
    cin >> n >> q;
    ll prefixes[n+1];
    prefixes[0] = 0;
    for(i=1; i<=n; i++)
    {
        cin >> a;
        prefixes[i] = prefixes[i-1] + a;
    }

    for(i=0; i<q; i++)
    {
        cin >> l >> r;
        ll result = prefixes[r] - prefixes[l];
        cout << result << endl;
    }

    return 0;
}