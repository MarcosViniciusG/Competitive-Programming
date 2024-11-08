#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;


    ll salt = p/np;
    ll limes = c*d;
    ll ml = k * l / nl;

    cout << min(salt, min(limes, ml)) / n << endl;

    return 0;
}