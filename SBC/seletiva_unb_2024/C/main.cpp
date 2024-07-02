#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, M, a, b, c, i;
    cin >> N >> M;
    int as[N], bs[N], cs[N];

    for(i=0; i<N; i++)
    {
        cin >> a;
        as[i] = a;
    }

    for(i=0; i<N; i++)
    {
        cin >> b;
        bs[i] = b;
    }

    for(i=0; i<N; i++)
    {
        cin >> c;
        cs[i] = c;
    }

    vector<int> custos;
    for(i=0; i<N; i++)
    {
        int custo = (as[i] - bs[i]) * cs[i];
        if(custo > 0)
            custos.push_back(custo);
    }

    sort(custos.begin(), custos.end());
    vector<int> prefixes;
    int soma = 0;
    for(auto n: custos)
    {
        soma += n;
        prefixes.push_back(soma);
    }

    int maior=0;
    soma = 0;
    for(auto p: prefixes)
    {
        soma += p;
        if(soma <= M)
            maior += 1;
    }

    cout << maior << endl;
    
    return 0;
}