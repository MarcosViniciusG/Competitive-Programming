#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll t, n, k, ai, i, j, maior, moves;
    cin >> t;
    while(t--)
    {
        maior=0;
        moves=0;
        cin >> n >> k;
        for(i=0; i<k; i++)
        {
            cin >> ai;

            moves += (ai - 1) + ai;

            maior = max(maior, ai);
        }

        moves -= ((maior - 1) + maior);
        cout << moves << endl;
    }

    return 0;
}