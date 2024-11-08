#include <bits/stdc++.h>

using namespace std;
int main()
{
    string codigo;
    queue<int> trad;
    cin >> codigo;

    for(int i=0; i<codigo.size(); i++)
    {
        if(codigo[i] == '-')
        {
            if(codigo[i+1] == '.') trad.push(1);
            else if (codigo[i + 1] == '-') trad.push(2);

            i++;
        }
        else trad.push(0);
    }

    while(trad.size() != 0)
    {
        cout << trad.front();
        trad.pop();
    }

    cout << endl;

    return 0;
}