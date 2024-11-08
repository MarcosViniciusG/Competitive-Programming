#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, a, maior=-1, menor=101, trocas, dist_maior, dist_menor;
    cin >> n;
    vector<int> fila(n);

    for(int i=0; i<n; i++)
    {
        cin >> a;
        fila[i] = a;
        if(maior == -1 || a > fila[maior])
        {
            dist_maior = i;
            maior = i;
        }

        if(menor==101 || a <= fila[menor])
        {
            menor = i;
            dist_menor = (n - 1) - i;
        }
    }
    
    trocas = dist_maior + dist_menor;
    if(maior > menor) trocas--;

    cout << trocas << endl;

    return 0;
}