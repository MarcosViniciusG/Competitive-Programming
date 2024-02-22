#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, p;
    long long int soma=0;
    cin >> n;
    double porcentagem = 100 * n;
    for(int i=0; i<n; i++)
    {
        cin >> p;
        soma += p;
    }

    cout << 100 * (soma / porcentagem) << endl;
}