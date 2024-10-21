#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, M, a, b, c, i, maior;
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
    int l = 1;
    int r = custos.size();
    while(r!=l)
    {
        int mid = (l + r)/2;
        if(custos[mid] <= M)
        {
            l = mid + 1;
            maior = mid;
        }
        else if (custos[mid] > M)
        {
            r = mid-1;
        }
    }  

    cout << maior << endl;
    
    return 0;
}