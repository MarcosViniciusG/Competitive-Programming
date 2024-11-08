#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, k, h, i, j;

    cin >> n >> k;
    vector<int> pre;
    int sum=0;
    pre.push_back(0);
    for(i=0; i<n; i++)
    {
        cin >> h;
        sum+=h;
        pre.push_back(sum);
    }

    // for(auto p: pre)
    //     cout << p << " ";
    // cout << endl;

    int p1=0;
    int p2=k;
    int menor = -1;
    int menor_idx;
    int maior_idx;
    while(p2 <= n)
    {
        if(menor==-1 || (pre[p2]-pre[p1]) < menor) {
            menor = pre[p2] - pre[p1];
            menor_idx = p1+1;
            maior_idx = p2;
        }
        p1++; p2++;
    }  

    cout << menor_idx << endl;
    return 0;
}