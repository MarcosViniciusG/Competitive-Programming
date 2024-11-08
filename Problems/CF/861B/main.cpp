#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin >> t;

    ll n, m, a, i, j, k, soma;
    while(t--)
    {
        cin >> n >> m;
        vector<vector<ll>>  matrix(m);
        soma = 0;

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin >> a;

                matrix[j].push_back(a);

                if(i==n-1)
                   sort(matrix[j].rbegin(), matrix[j].rend());
                   1;
            }
        }

        for(j=0; j<m; j++)
        {
            for(i=0, k=n-1; i<n; i++, k--)
            {
                //cout << matrix[j][i] << " ";
                soma += matrix[j][i] * (n-i-1) - matrix[j][i] * (n-k-1);
            }

            // cout << endl;
        }       
        cout << soma << endl;

    }

    return 0;
}