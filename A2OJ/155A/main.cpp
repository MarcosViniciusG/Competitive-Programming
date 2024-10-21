#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, a, maior, menor, amazing=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        if(i==0)
        {
            maior = a;
            menor = a;
        }
        
        if(a > maior) 
        {
            maior = a;
            amazing++;
        }

        if(a < menor) 
        {
            menor = a;
            amazing++;
        }
    }

    cout << amazing << endl;
    return 0;
}