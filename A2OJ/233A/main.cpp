#include <bits/stdc++.h>

using namespace std;
int main()
{
    string n;
    cin >> n;
    int num = stoi(n);
    if(num % 2) cout << -1 << endl;
    else
    {
        queue<int> fila;
        for(int i=0; i<num; i++)
        {
             if(i % 2) fila.push(i);
             else fila.push(i + 2);
        }
        
        
        while(fila.size() != 0)
        {
            cout << fila.front() << " ";
            fila.pop();
        }
        cout << endl;
    }

    return 0;
}