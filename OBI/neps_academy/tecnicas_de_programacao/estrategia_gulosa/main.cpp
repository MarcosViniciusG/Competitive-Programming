#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll V, S[6] = {1, 5, 10, 25, 50, 100}, moedas = 0;
    cin >> V;
    for (int i = 5; i >= 0 && V > 0; i--)
    {
        while(V >= S[i])
        {
            V -= S[i];
            moedas++;
        }
    }

    cout << moedas << endl;
    return 0;
}