#include <bits/stdc++.h>

using namespace std;
int main()
{
    priority_queue<char> fila1, fila2;
    string nome;

    cin >> nome;
    for(auto c: nome) fila1.push(c);

    cin >> nome;
    for(auto c: nome) fila1.push(c);

    cin >> nome;
    for(auto c: nome) fila2.push(c);

    while(fila1.size() && fila2.size() && fila1.top()==fila2.top())
    {
        fila1.pop();
        fila2.pop();
    }

    if(fila2.size()) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}