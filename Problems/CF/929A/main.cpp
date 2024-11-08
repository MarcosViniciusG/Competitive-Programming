#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t, n, a, soma;
    cin >> t;
    while(t--)
    {
        cin >> n;
        soma = 0;
        while(n--)
        {
            cin >> a;
            if(a < 0)
                soma += -a;
            else
                soma += a;
        }

        cout << soma << endl;
    }

    return 0;
}