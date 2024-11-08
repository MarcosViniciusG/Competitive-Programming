#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll k, l, m, n, d, i, harmed=0;
    cin >> k >> l >> m >> n >> d;

    for(int i=1; i<=d; i++)
    {
        if((i % k==0) || (i % l==0) || (i % m==0) || (i % n==0)) harmed++;
    }

    cout << harmed << endl;
    return 0;
}