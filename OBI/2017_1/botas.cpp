#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, M, count=0;
    cin >> N;
    list<int> direita;
    list<int> esquerda;

    char L;
    for(int i=0; i<N; i++)
    {
        cin >> M;
        cin.ignore(1, '\n');
        cin >> L;
        if(L=='D') direita.insert(direita.begin(), M);
        else if(L=='E') esquerda.insert(esquerda.begin() ,M);
    }

    auto ptr_d = direita.begin();
    auto ptr_e = esquerda.begin();

    while(ptr_d != direita.end())
    {
        ptr_e = esquerda.begin();
        while(ptr_e != esquerda.end())
        {
            if(*ptr_d == *ptr_e)
            {
                count++;
                esquerda.erase(ptr_e);
                break;
            }
            ptr_e++;
        }

        ptr_d++;
    }

    cout << count << endl;

    return 0;
}