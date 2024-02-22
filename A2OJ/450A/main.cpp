#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m, a, ultima, i;
    queue<pair<int, int>> fila;
    
    cin >> n >> m;
    for(i=0; i<n; i++)
    {
        cin >> a;
        fila.push(make_pair(i+1, a)); 
    }

    while(fila.size()!=0)
    {
        auto crianca = fila.front();
        fila.pop();
        ultima = crianca.first;
        if((crianca.second - m) > 0)
        {
            crianca.second -= m;
            fila.push(crianca);
        }
    }

    cout << ultima << endl;
    return 0;
}