#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, n;
    cin >> x >> y >> n;

    int it=1;
    while(x && y) {
        vector<int> arca(n, 0);

        int soma=x + y;
        for(int &i: arca) {
            cin >> i;
            soma += i;
        }

        int alvo = (soma/2) 
        int f[soma+1];

        cout << "Teste " << it << '\n';
        if(soma & 1)
            cout << 'N' << '\n';

        it++;
        cin >> x >> y >> n;
    } 


    return 0;
}