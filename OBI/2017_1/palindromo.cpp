#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, partes;
    string cadeia;
    cin >> N;
    cin.ignore(1, '\n');
    getline(cin, cadeia);

    auto ptr_i = cadeia.begin();
    auto ptr_f = cadeia.end();
    while (true)
    {
        if(*ptr_i == *ptr_f)
        {
            ptr_i++;
            ptr_f--;
        }
        else
        {
            ptr_i++;
            if(ptr_f!=cadeia.end())
        }
    }
    

    return 0;
}