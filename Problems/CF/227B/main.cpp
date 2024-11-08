#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll n, a, m, b, i, V=0, P=0;

    cin >> n;
    ll arr[n+1];
    for(i=0; i<n; i++)
    {
        cin >> a;
        arr[a] = i;
    }

    cin >> m;
    for(i=0; i<m; i++)
    {
        cin >> b;
        V += arr[b] + 1;
        P += n - arr[b];
    }

    cout << V << " " << P << endl;
    return 0;
}