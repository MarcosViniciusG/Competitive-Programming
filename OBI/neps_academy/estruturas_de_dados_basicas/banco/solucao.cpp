#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
    ll C, N, T, D, i, count=0;
    priority_queue<ll, vector<ll>, greater<ll>> caixas;

    cin >> C >> N;

    for(i=0; i<C; i++)
    {
        caixas.push(0);
    }

    for(i=0; i<N; i++)
    {
        cin >> T >> D;

        ll caixa = caixas.top();
        caixas.pop();

        if (caixa> T + 20) count++;

        caixas.push(max(caixa, T) + D);
    }

    cout << count << endl;
    return 0;
}