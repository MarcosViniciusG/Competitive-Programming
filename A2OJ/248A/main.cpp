#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll n, l, r, t=0, i, nlo=0, nro=0;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> l >> r;
        if(l) nlo++;
        if(r) nro++;
    }

    if(nlo >= (n - nlo)) t += n - nlo;
    else t += nlo;

    if(nro >= (n - nro)) t += n - nro;
    else t += nro;   

    cout << t << endl;
    return 0;
}