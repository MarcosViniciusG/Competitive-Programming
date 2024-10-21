#include <bits/stdc++.h>

using namespace std;
int main()
{
    string comandos;
    bool flag=false;
    getline(cin, comandos);
    for(auto c: comandos)
    {
        if(c=='H' || c=='Q' || c=='9')
        {
            flag=true;
            break;
        }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}