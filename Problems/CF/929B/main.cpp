#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll t, n, a, soma, moves, resto;
    vector<ll> seq1, seq2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        soma=0;
        moves=0;
        seq1.clear();
        seq2.clear();
        while(n--)
        {
            cin >> a;
            soma += a;

            if(a % 3)
            {
                if((a+2) % 3==0)
                    seq1.push_back(a);
                else if((a+1) % 3 ==0)
                    seq2.push_back(a);
            }
        }
        
        bool pos = false;
        resto = soma % 3;
        if(resto==1 && seq1.size() > 0)
            pos = true;
        else if(resto==2 && seq2.size() > 0)
            pos = true;

        if((soma + 1) % 3==0 || pos)
            moves = 1;
        else if((soma +2) % 3 == 0)
            moves = 2;

        cout << moves << endl;
    }

    return 0;
}