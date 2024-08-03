#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, f, maior, menor, menor_diff=3000;
    vector<int> pieces;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> f;
        pieces.push_back(f);
    }

    sort(pieces.begin(), pieces.end());
    for(int i=0; i<m-1; i++)
    {
        maior = pieces[i];
        menor = pieces[i];

        if(i+n == m+1)
            break;

        for(int j=i+1; j<i+n; j++)
        {
            if(pieces[j] > maior)
                maior=pieces[j];
            else if(pieces[j] < menor) 
                menor = pieces[j];
        }

        if(maior - menor < menor_diff)
            menor_diff = maior - menor;
    }

    cout << menor_diff << endl;
    return 0;
}