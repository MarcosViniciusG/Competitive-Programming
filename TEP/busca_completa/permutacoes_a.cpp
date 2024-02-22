#include <bits/stdc++.h>

using namespace std;

vector<int> conjunto = {0, 0, 0, 1};
vector<bool> escolhido (conjunto.size(), false);
vector<int> permutacao;

void search()
{
    if(permutacao.size()==conjunto.size())
    {
        for(int i=0; i<permutacao.size(); i++)
        {
            cout << permutacao[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for(int i=0; i<conjunto.size(); i++)
        {
            if(escolhido[i]) continue;
            escolhido[i] = true;
            permutacao.push_back(conjunto[i]);
            search();
            escolhido[i] = false;
            permutacao.pop_back();
        }
    }

}

int main()
{
    search();
    return 0;
}